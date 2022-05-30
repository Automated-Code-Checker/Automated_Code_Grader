import torch
import torch.nn as nn
import torch.nn.functional as F
from transformers import BertModel, BertConfig

class code2vec_model(nn.Module):
  """
  self.values_vocab_size - set of values of AST terminals that were observed during training
  self.paths_vocab_size - set of AST paths
  self.val_embedding_dim - size of embedding vector for values
  self.path_embedding_dim - size of embedding vector for values
  """
  def __init__(self, 
               val_embedding_dim = 128,
               path_embedding_dim = 128,
               dropout_rate = 0.25,
               embedding_dim = 128,
               values_vocab_size = 0,
               paths_vocab_size = 0,
               labels_num = 0,
               bert = False,
               bert_params = None):
    super().__init__()

    self.values_vocab_size = values_vocab_size
    self.paths_vocab_size = paths_vocab_size
    self.val_embedding_dim = val_embedding_dim
    self.path_embedding_dim = path_embedding_dim
    self.dropout_rate = dropout_rate
    self.embedding_dim = embedding_dim
    self.labels_num = labels_num
    self.bert = bert
    
    ## 1. Embeddings
    self.values_embedding = nn.Embedding(self.values_vocab_size, self.val_embedding_dim)
    self.paths_embedding = nn.Embedding(self.paths_vocab_size, self.path_embedding_dim)
    self.lstm = nn.LSTM(input_size=128*3,
                            hidden_size=self.embedding_dim,
                            num_layers=1,
                            batch_first=True,
                            bidirectional=True)
    ## 2. DropOut + tanh(Fully-connected layer) for combined context vectors
    self.DropOut = nn.Dropout(self.dropout_rate)
    # print("path_embedding_dim : ", type(self.path_embedding_dim))
    # print("val_embedding_dim : ", type(self.val_embedding_dim))
    self.linear = nn.Linear(self.path_embedding_dim + 2 * self.val_embedding_dim, self.embedding_dim, bias = False)
    self.a = nn.Parameter(torch.randn(1, self.embedding_dim))
    ## 4. Prediction
#     self.output_linear = nn.Linear(self.embedding_dim, self.labels_num, bias = False)
#     self.neg_INF = - 2 * 10**10
    
  def forward(self, starts, paths, ends):
      """
      input for starts,paths,ends - [[],[],[]...[]] - N_paths * BATCH_SIZE
      We form the indexed vocab of left_nodes, paths, right_nodes
      starts, paths, ends - lists of INDEXES of left_nodes, paths, right_nodes
      """
      
      ## 1. Embeddings
      start_embedding = self.values_embedding(starts)
      path_embedding = self.paths_embedding(paths)
      end_embedding = self.values_embedding(ends)

      ## 2. Concatecation of 3 vectors 
      context_vec = torch.cat((start_embedding, path_embedding, end_embedding), dim=2)
      context_vec, _ = self.lstm(context_vec)
      ## 3. Attention mechanism
      mask = (starts > 1).float() ## if 1 then it is pad and we don't pay attention to it
      ## 4. DropOut + Fully-connected layer into 'Combinied context vectors'
      comb_context_vec = torch.tanh(self.linear(context_vec))
      comb_context_vec = self.DropOut(comb_context_vec)
      lin_mul = torch.matmul(comb_context_vec, self.a.T)
      attention_weights = F.softmax(torch.mul(lin_mul, mask.view(lin_mul.size())) + (1 - mask.view(lin_mul.size())) * self.neg_INF, dim = 1)     
      code_vector = torch.sum(torch.mul(comb_context_vec, attention_weights), dim = 1)
      ## 5. Prediction
      output = self.output_linear(code_vector)
      
      return code_vector, output