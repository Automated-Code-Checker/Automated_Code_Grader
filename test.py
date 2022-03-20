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

from sklearn.metrics import accuracy_score

def main():

    LR = 3e-3
    WD = 0.8e-5

    SEED = 1337
    random.seed(SEED)
    torch.manual_seed(SEED)
    torch.cuda.manual_seed(SEED)
    torch.backends.cudnn.deterministic = True
    
    data_folder = 'Codes_embedding'
    dataset_name = 'Codes_embedding'


    dict_path = 'data/'+ data_folder + '/' + dataset_name + '.dict.c2v'
    word2idx, path2idx, target2idx, idx2target = create_vocab.create_vocab(dict_path)




    model = model_implementation.code2vec_model(values_vocab_size = len(word2idx), 
                            paths_vocab_size = len(path2idx), 
                            labels_num = len(target2idx))
    

    
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
            # break

    df = pd.DataFrame(data=d)
    display(df,)

    print("Accuracy : ",accuracy_score(df['Original names'], df['Predicted names']))

if __name__== "__main__":
  # batch_size = int(input('Input batch size: '))
  batch_size = 1024
  # lr = float(input('Input learning rate: '))
  lr = 0.01
  # wd = float(input('Input weight decay: '))
  wd = 0.01

  main()