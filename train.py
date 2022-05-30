import create_vocab
import data_to_tensors
import model_implementation
import json 
# import lstm_try as model_implementation 
from train_class import TrainingModule
import sys
import torch
import torch.nn as nn
import torch.nn.functional as F
import random 
import csv
from torch.utils.data import DataLoader
import pickle
import pandas as pd
from IPython.display import display


def main():
    
    bert = False

    N_EPOCHS = 100
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

    path_for_train = 'data/'+ data_root + '/' + data_root + '.train.c2v'
    train_dataset = data_to_tensors.TextDataset(path_for_train, 
                                                        word2idx, 
                                                        path2idx, 
                                                        target2idx)

    path_for_val = 'data/'+ data_root + '/' + data_root + '.val.c2v'
    val_dataset = data_to_tensors.TextDataset(path_for_val, 
                                                        word2idx, 
                                                        path2idx, 
                                                        target2idx)

    path_for_test = 'data/'+ data_root + '/' + data_root + '.test.c2v'
    test_dataset = data_to_tensors.TextDataset(path_for_test, 
                                                        word2idx, 
                                                        path2idx, 
                                                        target2idx)

    train_loader = DataLoader(train_dataset, batch_size=512, shuffle=True)
    val_loader = DataLoader(val_dataset, batch_size=512, shuffle=False)
    test_loader = DataLoader(test_dataset, batch_size=512, shuffle=False)

    # In case of bert
    bert_params = dict()
    bert_params['num_attention_heads'] = 1
    bert_params['num_transformer_layers'] = 1
    bert_params['intermediate_size'] = 32

    if bert:
        model = model_implementation.path_attention_model(values_vocab_size = len(word2idx), 
                                paths_vocab_size = len(path2idx), 
                                labels_num = len(target2idx), bert=bert, bert_params=bert_params)
    else:
         model = model_implementation.path_attention_model(values_vocab_size = len(word2idx),
                                 paths_vocab_size = len(path2idx),
                                 labels_num = len(target2idx))
    
    values = []
    values.append(dataset_name)
    values.append(len(word2idx))
    values.append(len(path2idx))
    values.append(len(target2idx))
    f = open('/Users/unaissiddiqui/Desktop/Fyp/Automated_Code_Grader/Values.csv', 'a')
    writer = csv.writer(f)
    writer.writerow(values)
    f.close()

    optimizer = torch.optim.Adam(model.parameters(), lr=LR, weight_decay=WD)
    criterion = nn.CrossEntropyLoss()

    train_class = TrainingModule(model, optimizer, criterion, train_loader, val_loader, test_loader, N_EPOCHS, idx2target)
    list_train_loss, list_val_loss, list_train_precision, list_val_precision,list_train_recall, list_val_recall, list_train_f1, list_val_f1,list_train_accuracy,list_val_accuracy = train_class.train(dataset_name)

    if bert == True:
        # state_dict = torch.load('best_model.pth')
        state_dict = torch.load('./Models/' + dataset_name + '_model.pth')
    else:
        kwargs, state = torch.load('./Models/' + dataset_name + '_model.pth')
        model = model_implementation.path_attention_model(**kwargs)
        model.load_state_dict(state)

    out_file = open("/Users/unaissiddiqui/Desktop/Fyp/Automated_Code_Grader/jsons/"+dataset_name+".json", "w") 
    json.dump(idx2target, out_file, indent = 4) 
    out_file.close()

    DEVICE = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")

    model = model.to(DEVICE)

    print("SAB KHATAM")

if __name__== "__main__":
  # batch_size = int(input('Input batch size: '))
  batch_size = 1024
  # lr = float(input('Input learning rate: '))
  lr = 0.01
  # wd = float(input('Input weight decay: '))
  wd = 0.01

  main()