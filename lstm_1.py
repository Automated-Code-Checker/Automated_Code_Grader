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

from sklearn.metrics import accuracy_score, classification_report, confusion_matrix, mean_squared_error, f1_score, balanced_accuracy_score, roc_auc_score, roc_curve, auc

import numpy as np

import matplotlib.pyplot as plt
from sklearn.metrics import RocCurveDisplay


# import seaborn as sns
########################################################################

data_root = 'non_divisible_emb'
dataset_name = 'non_divisible_emb'

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
# VOCAB_SIZE = len(word2idx) =  296
# HIDDEN_IN = 128

################################################################

def train_model(model, epochs=10, lr=0.001):
    parameters = filter(lambda p: p.requires_grad, model.parameters())
    optimizer = torch.optim.Adam(parameters, lr=lr)
    best_loss = 0
    # label_ = ['2','3','4','5','6','7','8','9','10','11','12']
    label_= [ i for i in range(4)]
    for i in range(epochs):
        model.train()
        sum_loss = 0.0
        total = 0
        print(i)
        pred_arr = []
        tar_arr = []
        scor_arr = []
        # for x, y, l in train_dl:
        # tars = [i for i in range(6)]
        tars = []
        one_hot = []
        y_score = []
        labels_orig = [i for i in range(6)]
        softmax = torch.nn.Softmax()
        for starts, paths, ends, targets in train_loader:
            # x = x.long()
            # y = y.long()
            y_pred = model(starts, paths, ends, targets)
            optimizer.zero_grad()
            loss = F.cross_entropy(y_pred, targets)
            loss.backward()
            optimizer.step()
            sum_loss += loss.item()*targets.shape[0]
            total += targets.shape[0]

            pred = torch.max(y_pred, 1)[1]
            idx = idx2target[targets.item()]

            zs = [0 for i in range(4)]
            # zs[targets ] = 1
            one_hot += [zs]
            tars += [targets.item()]
            # print(y_pred)
            # exit()
            y_score += [y_pred[0][targets.item()].item()]

            pred_arr += [pred.item()]


            out = y_pred
            x =out.detach().numpy().tolist()
            x = x[0][2:]
            bb = torch.FloatTensor(x)
            bb = softmax(bb)
            scor_arr += [bb.detach().numpy().tolist()]

            tar_arr += [targets.item()]
        # print( tars, y_score)



        # fpr, tpr, _ = roc_curve(tars, y_score, pos_label=10)
        # print( confusion_matrix(tar_arr, pred_arr, labels=[2,3,4,5]))
        # exit()



        # if i % 5 == 1:
        # print("train loss %.3f, val loss %.3f, val accuracy %.3f, and val rmse %.3f" % (sum_loss/total, val_loss, val_acc, val_rmse))
        # print( f1_score(targets, pred, average=None))
        # print(pred_arr)
        # print(tar_arr)
        ### YES ###
        # val_loss, val_acc, val_rmse = validation_metrics(model, val_loader)
        print('---------------------------------------')
        print( balanced_accuracy_score(tar_arr, pred_arr, adjusted=True), 'BAL ACC SCORE')
        print( accuracy_score(tar_arr, pred_arr), 'ACC SCORE')
        print( f1_score(tar_arr, pred_arr, average='weighted'), 'f1 SCORE')
        # macro_roc_auc_ovr = roc_auc_score(tars, scor_arr, multi_class="ovr")
        print('----------------- ROC -----------------')
        # print("One-vs-Rest ROC AUC scores:", macro_roc_auc_ovr)
        # per_metrics = classification_report(tar_arr, pred_arr, labels=label_, output_dict=True)
        # precision = per_metrics["weighted avg"]["precision"]
        # recall = per_metrics["weighted avg"]["recall"]
        # print(precision, 'precision')
        # print(recall, 'recall')






def validation_metrics (model, val_loader):
    model.eval()
    correct = 0
    total = 0
    sum_loss = 0.0
    sum_rmse = 0.0
    # for x, y, l in valid_dl:
    for starts, paths, ends, targets in val_loader:
        # x = x.long()
        # y = y.long()
        y_hat = model(starts, paths, ends, targets)
        loss = F.cross_entropy(y_hat, targets)
        pred = torch.max(y_hat, 1)[1]
        correct += (pred == targets).float().sum()
        total += targets.shape[0]
        sum_loss += loss.item()*targets.shape[0]
        sum_rmse += np.sqrt(mean_squared_error(pred, targets.unsqueeze(-1)))*targets.shape[0]
        # print( balanced_accuracy_score(targets, pred, adjusted=True), 'BAL ACC SCORE')
        # print( 'y-pred', pred, '        y_true', targets)
        # print( accuracy_score(targets, pred, ), 'ACC SCORE')
    return sum_loss/total, correct/total, sum_rmse/total

################################################################

vocab_size = len(word2idx)
embedding_dim = 128
hidden_dim = 128

class LSTM_fixed_len(torch.nn.Module) :
    def __init__(self, vocab_size, embedding_dim, hidden_dim) :
        #
        super().__init__()
        
        self.embeddings = nn.Embedding(vocab_size, embedding_dim, padding_idx=0)

        self.values_embedding = nn.Embedding(len(word2idx), embedding_dim, padding_idx=0)
        self.paths_embedding = nn.Embedding(len(path2idx), embedding_dim, padding_idx=0)

        self.lstm = nn.LSTM(embedding_dim, hidden_dim, batch_first=True)
        self.linear = nn.Linear(384, hidden_dim)

        self.linear2 = nn.Linear(hidden_dim, 5)
        # self.linear2 = nn.Linear(hidden_dim, 13)
        self.dropout = nn.Dropout(0.2)
        
    def forward(self, starts, paths, ends, targets):

        # x = self.embeddings(x)

        start_embedding = self.values_embedding(starts)
        path_embedding = self.paths_embedding(paths)
        end_embedding = self.values_embedding(ends)

        context_vec = torch.cat((start_embedding, path_embedding, end_embedding), dim=2)
        # comb_context_vec = torch.tanh(self.linear(context_vec))
        comb_context_vec = self.linear(context_vec)

        # x = self.embeddings(context_vec[0])

        x = self.dropout(comb_context_vec)
        lstm_out, (ht, ct) = self.lstm(x)

        return self.linear2(ht[-1])


model_fixed =  LSTM_fixed_len(vocab_size, 128, 128)
train_model(model_fixed, epochs=30, lr=0.01)