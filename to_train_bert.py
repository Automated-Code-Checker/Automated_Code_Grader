import create_vocab
import data_to_tensors
import model_implementation
from train_class import TrainingModule

import pandas as pd
from IPython.display import display

import torch
import torch.nn as nn
import torch.nn.functional as F
import random 
from torch.utils.data import DataLoader

try:
    import transformers
except:
    raise RuntimeError('Please: pip install transformers')

def main(batch_size, lr, wd):
    SEED = 1337
    random.seed(SEED)
    torch.manual_seed(SEED)
    torch.cuda.manual_seed(SEED)
    torch.backends.cudnn.deterministic = True
    

    dict_path = 'data/unique_ids2_emb/unique_ids2_emb.dict.c2v'
    word2idx, path2idx, target2idx, idx2target = create_vocab.create_vocab(dict_path)

    path_for_train = 'data/unique_ids2_emb/unique_ids2_emb.train.c2v'
    train_dataset = data_to_tensors.TextDataset(path_for_train, 
                                                        word2idx, 
                                                        path2idx, 
                                                        target2idx)

    path_for_val = 'data/unique_ids2_emb/unique_ids2_emb.val.c2v'
    val_dataset = data_to_tensors.TextDataset(path_for_val, 
                                                        word2idx, 
                                                        path2idx, 
                                                        target2idx)
                                                        
    path_for_test = 'data/unique_ids2_emb/unique_ids2_emb.test.c2v'
    test_dataset = data_to_tensors.TextDataset(path_for_test, 
                                                        word2idx, 
                                                        path2idx, 
                                                        target2idx)
                                                        
    train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
    val_loader = DataLoader(val_dataset, batch_size=batch_size, shuffle=False)  
    test_loader = DataLoader(test_dataset, batch_size=batch_size, shuffle=False)

    bert = True
    bert_params = dict()
    bert_params['num_attention_heads'] = 1
    bert_params['num_transformer_layers'] = 1
    bert_params['intermediate_size'] = 32
        
    model = model_implementation.code2vec_model(values_vocab_size = len(word2idx), 
                                 paths_vocab_size = len(path2idx), 
                                 labels_num = len(target2idx), bert=bert, bert_params=bert_params)
    ########################################################################################
    N_EPOCHS = 40
    LR = lr
    WD = wd

    optimizer = torch.optim.Adam(model.parameters(), lr=LR, weight_decay=WD)
    criterion = nn.CrossEntropyLoss()

    train_class = TrainingModule(model, optimizer, criterion, train_loader, val_loader, test_loader, N_EPOCHS, idx2target)
    _, _, _, _,_, _, _, _ = train_class.train()

    # APNA CODE
    state_dict = torch.load('best_model.pth')
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
    
    main(batch_size, lr, wd)

