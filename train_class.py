import torch
import torch.nn as nn
from torch.nn import functional as F
from metrics import precision_recall_f1
from time import time

class TrainingModule:
    def __init__(self, model, optimizer, criterion, train_loader, val_loader, test_loader,
        epochs, idx2target_vocab, scheduler = None, checkpoint = True, early_stop = True):
        self.model = model
        self.optimizer = optimizer
        self.criterion = criterion
        self.train_loader = train_loader
        self.val_loader = val_loader
        self.test_loader = test_loader
        self.epochs = epochs
        self.idx2target_vocab = idx2target_vocab
        self.scheduler = scheduler
        self.checkpoint = checkpoint
        self.early_stop = early_stop
        self.DEVICE = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
        
    def train(self,dataset):
        list_train_loss = []
        list_val_loss = []
        list_train_precision = []
        list_val_precision = []
        list_train_recall = []
        list_val_recall = []
        list_train_f1 = []
        list_val_f1 = []
        list_train_accuracy = []
        list_val_accuracy = []
        
        best_val_f1 = float('+inf')
        
        self.model.to(self.DEVICE)
        self.criterion = self.criterion.to(self.DEVICE)

        self.dataset = dataset
        itr=0
        for epoch in range(self.epochs):
          
            start_time = time()

            train_loss, train_precision, train_recall, train_f1,train_accuracy = self.run_epoch(mode = 'train', dataloader = self.train_loader)
            val_loss, val_precision, val_recall, val_f1,val_accuracy = self.run_epoch(mode = 'val', dataloader = self.val_loader)

            list_train_loss.append(train_loss)
            list_val_loss.append(val_loss)

            list_train_precision.append(train_precision)
            list_val_precision.append(val_precision)

            list_train_recall.append(train_recall)
            list_val_recall.append(val_recall)

            list_train_f1.append(train_f1)
            list_val_f1.append(val_f1)

            list_train_accuracy.append(train_accuracy)
            list_val_accuracy.append(val_accuracy)
            
            # checkpoint
            if val_f1 < best_val_f1:
                best_val_f1 = val_f1
                
                torch.save(self.model.state_dict(), './Models/' + self.dataset + '_model.pth')
            
            if self.scheduler is not None:
                self.scheduler.step(train_loss)

            if self.early_stop:
                if epoch > 10:
                    if list_val_accuracy[-1] == list_val_accuracy[-2] and list_val_accuracy[-2] == list_val_accuracy[-3]:
                        break

            print('Epoch {}: train loss - {}, validation loss - {}'.format(epoch+1, round(train_loss,5), round(val_loss,5)))
            print('\t Validation: precision - {}, recall - {}, f1_score - {}'.format(round(val_precision,5), round(val_recall,5), round(val_f1,5)))
            print('\t  accuracy - {}'.format(round(val_accuracy,5)))
            
            print ('Elapsed time: %.3f' % (time() - start_time))
            print('----------------------------------------------------------------------')
            
        return list_train_loss , list_val_loss, list_train_precision, list_val_precision, list_train_recall, list_val_recall, list_train_f1, list_val_f1,list_train_accuracy,list_val_accuracy


    def run_epoch(self, mode, dataloader):
      
        if mode == 'train':
            self.model.train()
        else:
            self.model.eval()

        epoch_loss = 0.0
        epoch_tp, epoch_fp, epoch_fn,epoch_tn = 0.0, 0.0, 0.0, 0.0
        
        num_batches = 0
        for starts, contexts, ends, labels in dataloader:
            starts, contexts, ends = starts.to(self.DEVICE), contexts.to(self.DEVICE), ends.to(self.DEVICE)
            labels = labels.to(self.DEVICE)
            
            _, y_pred = self.model(starts, contexts, ends)
            loss = self.criterion(y_pred, labels)
            tp, fp, fn, tn = precision_recall_f1(y_pred, labels, self.idx2target_vocab)
            epoch_tp += tp
            epoch_fp += fp
            epoch_fn += fn
            
            if mode == 'train':
                self.optimizer.zero_grad()
                loss.backward()
                self.optimizer.step()

            epoch_loss += loss.item()
            num_batches += 1
            
            if self.early_stop:
                break
        
        num_batches = float(num_batches)
        epoch_tp, epoch_fp, epoch_fn, epoch_tn= float(epoch_tp), float(epoch_fp), float(epoch_fn),float(tn)
        epsilon = 1e-7
        accuracy = (epoch_tp + epoch_tn)/(epoch_tp + epoch_fp + epoch_fn + epoch_tn)
        precision = epoch_tp / (epoch_tp + epoch_fp + epsilon)
        recall = epoch_tp / (epoch_tp + epoch_fn + epsilon)
        f1 = 2 * precision * recall / (precision + recall + epsilon)


        return epoch_loss/num_batches, precision, recall, f1, accuracy
