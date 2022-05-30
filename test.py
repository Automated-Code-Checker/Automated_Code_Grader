from cProfile import label
import create_vocab
import data_to_tensors
from train_class import TrainingModule
import sys
import torch
import torch.nn as nn
import torch.nn.functional as F
import random 
import json
import pickle
import pandas as pd
from torch.utils.data import DataLoader
import model_implementation
import glob
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
    
    data_root = 'Codes_embeddings'
    dataset_name = sys.argv[1]

    dict_path = 'data/'+ data_root + '/' + data_root + '.dict.c2v'
    word2idx, path2idx, target2idx, idx2target = create_vocab.create_vocab(dict_path)

    path_for_data = 'data/'+ data_root + '/' + data_root + '.data.c2v'
    dataset = data_to_tensors.TextDataset(path_for_data, 
                                                        word2idx, 
                                                        path2idx, 
                                                        target2idx)
    
    data_loader = DataLoader(dataset, batch_size=1024, shuffle=False) 


    kwargs, state = torch.load('./Models/' + dataset_name + '_model.pth')
    model = model_implementation.path_attention_model(**kwargs)
    model.load_state_dict(state)


    with open("/Users/unaissiddiqui/Desktop/Fyp/Automated_Code_Grader/jsons/"+dataset_name+".json") as json_file:
        idx2target_1 = json.load(json_file)

    DEVICE = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

    d = {'Predicted names': []}

    d = {'File names': [], 'Predicted Marks': []}
    

    for start, path, end, label in iter(data_loader):
        # get from model
        code, y_pred = model.forward(start.to(DEVICE), path.to(DEVICE), end.to(DEVICE))
        # get probability
        y_pred = F.softmax(y_pred)
        # get best name index
        y_pred = torch.argmax(y_pred, dim = 1)
        
        for i,j in zip(label,y_pred):
            d['File names'].append(idx2target[i.item()])
            d['Predicted Marks'].append(idx2target_1[str(j.item())])

    df = pd.DataFrame(data=d)
    with pd.option_context('display.max_rows', 18, 'display.max_columns', 18):  # more options can be specified also
        print(df)

if __name__== "__main__":
  # batch_size = int(input('Input batch size: '))
  batch_size = 1024
  # lr = float(input('Input learning rate: '))
  lr = 0.01
  # wd = float(input('Input weight decay: '))
  wd = 0.01

  main()