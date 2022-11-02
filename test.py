from cProfile import label
import create_vocab
import data_to_tensors
import model_implementation
from train_class import TrainingModule
import sys
import torch
import torch.nn as nn
import torch.nn.functional as F
import random 

from torch.utils.data import DataLoader

import pandas as pd
from IPython.display import display

from sklearn.metrics import accuracy_score

def main():

    LR = 3e-3
    WD = 0.8e-5
    model= 0
    SEED = 1337
    random.seed(SEED)
    torch.manual_seed(SEED)
    torch.cuda.manual_seed(SEED)
    torch.backends.cudnn.deterministic = True
    
    data_root = 'q1_emb'
    dataset_name = sys.argv[1]

    dict_path = 'data/'+ data_root + '/' + data_root + '.dict.c2v'
    word2idx, path2idx, target2idx, idx2target = create_vocab.create_vocab(dict_path)

    # path_for_data = 'data/'+ data_root + '/' + data_root + '.data.c2v'
    # dataset = data_to_tensors.TextDataset(path_for_data, 
    #                                                     word2idx, 
    #                                                     path2idx, 
    #                                                     target2idx)

    path_for_test = 'data/'+ data_root + '/' + dataset_name + '.test.c2v'
    test_dataset = data_to_tensors.TextDataset(path_for_test, 
                                                        word2idx, 
                                                        path2idx, 
                                                        target2idx)


    # data_loader = DataLoader(dataset, batch_size=512, shuffle=False)    
    data_loader = DataLoader(test_dataset, batch_size=512, shuffle=False)    
    
    model = model_implementation.code2vec_model()

    state_dict = torch.load( dataset_name + '_article_model.pth' )

    model.load_state_dict(state_dict)

    DEVICE = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

    d = {'Predicted names': []}

    model = model.to(DEVICE)

    for start, path, end, label in iter(data_loader):
        # get from model
        code, y_pred = model(start.to(DEVICE), path.to(DEVICE), end.to(DEVICE))
        # get probability
        y_pred = F.softmax(y_pred)
        # get best name index
        y_pred = torch.argmax(y_pred, dim = 0)
        
        for i in y_pred:
            d['Predicted names'].append(idx2target[i.item()])

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