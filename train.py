import create_vocab
import data_to_tensors
import model_implementation
from train_class import TrainingModule

import torch
import torch.nn as nn
import torch.nn.functional as F
import random 

from torch.utils.data import DataLoader

import pandas as pd
from IPython.display import display



def main():
    
    bert = False

    N_EPOCHS = 40
    LR = 3e-3
    WD = 0.8e-5

    SEED = 1337
    random.seed(SEED)
    torch.manual_seed(SEED)
    torch.cuda.manual_seed(SEED)
    torch.backends.cudnn.deterministic = True
    
    data_root = 'unique_ids2_emb'
    dataset_name = 'unique_ids2_emb'

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

    train_loader = DataLoader(train_dataset, batch_size=512, shuffle=True)
    val_loader = DataLoader(val_dataset, batch_size=512, shuffle=False)
    test_loader = DataLoader(train_dataset, batch_size=512, shuffle=False)

    # In case of bert
    bert_params = dict()
    bert_params['num_attention_heads'] = 1
    bert_params['num_transformer_layers'] = 1
    bert_params['intermediate_size'] = 32

    if bert:
        model = model_implementation.code2vec_model(values_vocab_size = len(word2idx), 
                                paths_vocab_size = len(path2idx), 
                                labels_num = len(target2idx), bert=bert, bert_params=bert_params)
    else:
         model = model_implementation.code2vec_model(values_vocab_size = len(word2idx), 
                                 paths_vocab_size = len(path2idx), 
                                 labels_num = len(target2idx))
    

    optimizer = torch.optim.Adam(model.parameters(), lr=LR, weight_decay=WD)
    criterion = nn.CrossEntropyLoss()

    train_class = TrainingModule(model, optimizer, criterion, train_loader, val_loader, test_loader, N_EPOCHS, idx2target)
    list_train_loss, list_val_loss, list_train_precision, list_val_precision,list_train_recall, list_val_recall, list_train_f1, list_val_f1 = train_class.train(bert, dataset_name)

    if bert == True:
        # state_dict = torch.load('best_model.pth')
        state_dict = torch.load('./' + dataset_name + '_bert_model.pth')
    else:
        state_dict = torch.load( './' + dataset_name + '_article_model.pth')

    model.load_state_dict(state_dict)

    DEVICE = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

    model = model.to(DEVICE)

    d = {'Original names': [], 'Predicted names': []}

    for start, path, end, label in iter(test_loader):
        # get from model
        code, y_pred = model(start.to(DEVICE), path.to(DEVICE), end.to(DEVICE))
        # get probability
        y_pred = F.softmax(y_pred)
        # get best name index
        y_pred = torch.argmax(y_pred, dim = 1)
        
        for i, j in zip(label, y_pred):
            d['Original names'].append(idx2target[i.item()])
            d['Predicted names'].append(idx2target[j.item()])
            break

    df = pd.DataFrame(data=d)
    display(df,)

if __name__== "__main__":
  # batch_size = int(input('Input batch size: '))
  batch_size = 1024
  # lr = float(input('Input learning rate: '))
  lr = 0.01
  # wd = float(input('Input weight decay: '))
  wd = 0.01

  main()