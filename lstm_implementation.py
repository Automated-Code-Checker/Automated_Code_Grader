from matplotlib.style import context
import torch
import torch.nn as nn
import torch.nn.functional as F

import create_vocab
import data_to_tensors

import random 

from torch.utils.data import DataLoader
from torch.nn.utils.rnn import pack_padded_sequence, pad_packed_sequence, pad_sequence, pack_sequence


import pandas as pd
from IPython.display import display

import matplotlib.pyplot as plt
import pandas as pd

import torch.optim as optim

from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
# import seaborn as sns
########################################################################

data_root = 'CODES_emb'
dataset_name = 'CODES_emb'

dict_path = 'data/'+ data_root + '/' + dataset_name + '.dict.c2v'
word2idx, path2idx, target2idx, idx2target = create_vocab.create_vocab(dict_path)

path_for_train = 'data/'+ data_root + '/' + dataset_name + '.train.c2v'
train_dataset = data_to_tensors.TextDataset(path_for_train, 
                                                    word2idx, 
                                                    path2idx, 
                                                    target2idx)

path_for_val = 'data/'+ data_root + '/' + dataset_name + '.val.c2v'
val_dataset = data_to_tensors.TextDataset(path_for_val, 
                                                    word2idx, 
                                                    path2idx, 
                                                    target2idx)

path_for_test = 'data/'+ data_root + '/' + dataset_name + '.test.c2v'
test_dataset = data_to_tensors.TextDataset(path_for_test, 
                                                    word2idx, 
                                                    path2idx, 
                                                    target2idx)

# train_loader = DataLoader(train_dataset, batch_size=512, shuffle=True)
# val_loader = DataLoader(val_dataset, batch_size=512, shuffle=False)
# test_loader = DataLoader(test_dataset, batch_size=512, shuffle=False)
train_loader = DataLoader(train_dataset, shuffle=True)
val_loader = DataLoader(val_dataset, shuffle=False)
test_loader = DataLoader(test_dataset, shuffle=False)

# MAX_LENGTH = 10630
# VOCAB_SIZE = len(path2idx) = 296
# HIDDEN_IN = 128

################################################################

class LSTM(nn.Module):

    def __init__(self, dimension=512):
        super(LSTM, self).__init__()

        self.value_embedding = nn.Embedding(len(word2idx), 128)
        self.path_embedding = nn.Embedding(len(path2idx), 128)
        self.dimension = dimension
        
        self.lstm = nn.LSTM(input_size=128,
                            hidden_size=dimension,
                            num_layers=1,
                            batch_first=True,
                            bidirectional=False)
        self.drop = nn.Dropout(p=0.5)

        self.fc = nn.Linear(2*dimension, 1)

        # self.linear = nn.Linear(self.path_embedding_dim + 2 * self.val_embedding_dim, self.embedding_dim, bias = False)
        # self.linear = nn.Linear(128 + 2 * 128, 128, bias = False)
        self.linear = nn.Linear(128, 128, bias = False)


    # def forward(self, text, text_len):
    def forward(self, starts, paths, ends):

        # text_emb = self.embedding(text)
        start_embedding = self.value_embedding(starts)
        # [1,200,128]
        path_embedding = self.path_embedding(paths)
        end_embedding = self.value_embedding(ends)
        # [1,200,128]

        context_vec = torch.cat((start_embedding, path_embedding, end_embedding))
        # [3, 200, 128]
        # [batch, seq, features]

        # packed_input = pack_padded_sequence(context_vec, torch.as_tensor(len(word2idx), dtype=torch.int64), batch_first=True, enforce_sorted=False)
        # packed_input = pack_sequence(context_vec) #'torch.nn.utils.rnn.PackedSequence'
        # print(type(packed_input))
        # torch.set_printoptions(profile="full")
        # print(packed_input.data)
        comb_context_vec = torch.tanh(self.linear(context_vec))
        packed_output, _ = self.lstm(comb_context_vec)
        # print(_.shape)
        # exit()

        # output, _ = pad_sequence(packed_output)
        output = packed_output
        # print(output.size())
        # print(len(output))
        # exit()

        # out_forward =  output[range(len(output)), 128 - 1, :self.dimension]
        # # exit()
        # # out_forward = output[range( len(word2idx)) ,self.dimension]
        # out_reverse = output[:, 0, self.dimension:]
        # out_reduced = torch.cat((out_forward, out_reverse), 1)
        # path_fea = self.drop(out_reduced)

        # path_fea = self.fc(path_fea)
        # path_fea = torch.squeeze(path_fea, 1)
        # label_out = torch.sigmoid(path_fea)

        label_out = torch.sigmoid((output.data))

        return label_out

# Save and Load Functions

def save_checkpoint(save_path, model, optimizer, valid_loss):

    if save_path == None:
        return
    
    state_dict = {'model_state_dict': model.state_dict(),
                'optimizer_state_dict': optimizer.state_dict(),
                'valid_loss': valid_loss}
    
    torch.save(state_dict, save_path)
    print(f'Model saved to ==> {save_path}')


def load_checkpoint(load_path, model, optimizer):

    if load_path==None:
        return
    
    state_dict = torch.load(load_path, map_location="cpu")
    print(f'Model loaded from <== {load_path}')
    
    model.load_state_dict(state_dict['model_state_dict'])
    optimizer.load_state_dict(state_dict['optimizer_state_dict'])
    
    return state_dict['valid_loss']


def save_metrics(save_path, train_loss_list, valid_loss_list, global_steps_list):

    if save_path == None:
        return
    
    state_dict = {'train_loss_list': train_loss_list,
                'valid_loss_list': valid_loss_list,
                'global_steps_list': global_steps_list}
    
    torch.save(state_dict, save_path)
    print(f'Model saved to ==> {save_path}')


def load_metrics(load_path):

    if load_path==None:
        return
    
    state_dict = torch.load(load_path, map_location="cpu")
    print(f'Model loaded from <== {load_path}')
    
    return state_dict['train_loss_list'], state_dict['valid_loss_list'], state_dict['global_steps_list']

# Training Function

def train(model,
          optimizer,
        #   criterion = nn.BCELoss(),
          criterion = nn.CrossEntropyLoss(),
          train_loader = train_loader,
          valid_loader = val_loader,
          num_epochs = 5,
          eval_every = len(train_loader) // 2,
          file_path = "lstm_model",
          best_valid_loss = float("Inf")):
    
    # initialize running values
    running_loss = 0.0
    valid_running_loss = 0.0
    global_step = 0
    train_loss_list = []
    valid_loss_list = []
    global_steps_list = []

    # training loop
    model.train()
    for epoch in range(num_epochs):
        # for (labels, (title, title_len), (text, text_len), (titletext, titletext_len)), _ in train_loader:           
        for starts, contexts, ends, labels in train_loader:
            # labels = labels.to("cpu")
            starts, contexts, ends = starts.to("cpu"), contexts.to("cpu"), ends.to("cpu")
            # output = model(titletext, titletext_len)
            # print(labels)
            labels = labels.to("cpu")

            # _, y_pred = model(starts, contexts, ends)
            y_pred = model(starts, contexts, ends)
            # y_pred.shape = [600, 1024]

            print(y_pred.shape, '****************************************************************')
            print(labels, '----------')

            loss = criterion(y_pred, labels)
            optimizer.zero_grad()
            loss.backward()
            optimizer.step()

            # update running values
            running_loss += loss.item()
            global_step += 1

            # evaluation step
            if global_step % eval_every == 0:
                model.eval()
                with torch.no_grad():                    
                  # validation loop
                  for (labels, (title, title_len), (text, text_len), (titletext, titletext_len)), _ in valid_loader:
                      labels = labels.to("cpu")
                      titletext = titletext.to("cpu")
                      titletext_len = titletext_len.to("cpu")
                      output = model(titletext, titletext_len)

                      loss = criterion(output, labels)
                      valid_running_loss += loss.item()

                # evaluation
                average_train_loss = running_loss / eval_every
                average_valid_loss = valid_running_loss / len(valid_loader)
                train_loss_list.append(average_train_loss)
                valid_loss_list.append(average_valid_loss)
                global_steps_list.append(global_step)

                # resetting running values
                running_loss = 0.0                
                valid_running_loss = 0.0
                model.train()

                # print progress
                print('Epoch [{}/{}], Step [{}/{}], Train Loss: {:.4f}, Valid Loss: {:.4f}'
                      .format(epoch+1, num_epochs, global_step, num_epochs*len(train_loader),
                              average_train_loss, average_valid_loss))
                
                # checkpoint
                if best_valid_loss > average_valid_loss:
                    best_valid_loss = average_valid_loss
                    save_checkpoint(file_path + '/model.pt', model, optimizer, best_valid_loss)
                    save_metrics(file_path + '/metrics.pt', train_loss_list, valid_loss_list, global_steps_list)
    
    save_metrics(file_path + '/metrics.pt', train_loss_list, valid_loss_list, global_steps_list)
    print('Finished Training!')


model = LSTM().to("cpu")
optimizer = optim.Adam(model.parameters(), lr=0.001)

train(model=model, optimizer=optimizer, num_epochs=10)