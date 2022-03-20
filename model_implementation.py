import torch
import torch.nn as nn
import torch.nn.functional as F


class code2vec_model(nn.Module):
  ########################################################
  #self.values_vocab_size - set of values of AST terminals t hat were observed during training
  #self.paths_vocab_size - set of AST paths
  #self.val_embedding_dim - size of embedding vector for values
  #self.path_embedding_dim - size of embedding vector for values
  #########################################################
  def __init__(self, 
               val_embedding_dim = 128,
               path_embedding_dim = 128,
               dropout_rate = 0.25,
               embedding_dim = 128,
               values_vocab_size = 0,
               paths_vocab_size = 0,
               labels_num = 0):
    super().__init__()

    self.values_vocab_size = values_vocab_size
    self.paths_vocab_size = paths_vocab_size
    self.val_embedding_dim = val_embedding_dim
    self.path_embedding_dim = path_embedding_dim
    self.dropout_rate = dropout_rate
    self.embedding_dim = embedding_dim
    self.labels_num = labels_num
    
    #to store embeddings of a fixed size(dict size) vs dim(size of emb vector)
    self.values_embedding = nn.Embedding(self.values_vocab_size, self.val_embedding_dim)
    self.paths_embedding = nn.Embedding(self.paths_vocab_size, self.path_embedding_dim)
   
    #randomly converts to 0 in order to prevent overfitting 
    self.DropOut = nn.Dropout(self.dropout_rate)
    
    #Linear transformation on incomming data with size x , y as output_sample data size
    self.linear = nn.Linear(self.path_embedding_dim + 2 * self.val_embedding_dim, self.embedding_dim, bias = False)
    
    #here torch.randn() would return 1 tensor starting of size embedding_dim
    self.a = nn.Parameter(torch.randn(1, self.embedding_dim))

    #Linear transformation on incomming data with size x , y as output_sample data size = labels
    self.output_linear = nn.Linear(self.embedding_dim, self.labels_num, bias = False)
    #mereko nai pata
    self.neg_INF = - 2 * 10**10

  def forward(self, starts, paths, ends):
    ##################################################################
    #input for starts,paths,ends - [[],[],[]...[]] - N_paths * BATCH_SIZE
    #We form the indexed vocab of left_nodes, paths, right_nodes
    ##starts, paths, ends - lists of INDEXES of left_nodes, paths, right_nodes
    ####################################################################
    
    #Assign respective embeddings
    start_embedding = self.values_embedding(starts)
    path_embedding = self.paths_embedding(paths)
    end_embedding = self.values_embedding(ends)
    #concatenate the start-node, path, and end-node embeddings to create a single context
    context_vec = torch.cat((start_embedding, path_embedding, end_embedding), dim=2)
    #Attention mechanism -> states that if the start-node is 1 i.e starting wala then no attention
    mask = (starts > 1).float() 

    #self.linear-> accepts a input sample and outputs linear transformed, output of this into => Fully-connected layer
    comb_context_vec = torch.tanh(self.linear(context_vec))
    #droupout again
    comb_context_vec = self.DropOut(comb_context_vec)

    #mul com_context tensor with parameter tensor-> code2vec paper methodology
    lin_mul = torch.matmul(comb_context_vec, self.a.T)
    #apply softmax activation to calculate attention weights
    attention_weights = F.softmax(torch.mul(lin_mul, mask.view(lin_mul.size())) + (1 - mask.view(lin_mul.size())) * self.neg_INF, dim = 1)
    #code_vector created w.r.t each comb_context vector and its weight
    code_vector = torch.sum(torch.mul(comb_context_vec, attention_weights), dim = 1)
    #Prediction
    output = self.output_linear(code_vector)
    
    return code_vector, output
