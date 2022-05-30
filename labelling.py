import os
import pandas as pd
from IPython.display import display

df_emb = pd.read_csv('data/functions_emb/functions_emb.raw.txt', sep='\n', header=None)
df_emb.columns = ['Embeddings']
df_marks = pd.read_csv('marks/functions_emb_nums.csv', header=None)
df_marks.columns = ['Marks']
# df_marks['Marks']= df_marks['Marks'].map(str)
df = pd.concat([df_marks, df_emb ], axis=1, join='outer')
display( df, )

df.to_csv('data/functions_emb/functions_emb.raw1.txt', sep='-', header=None , mode='w', index=False)