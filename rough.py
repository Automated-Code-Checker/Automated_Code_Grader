import os
import pandas as pd
from IPython.display import display

# ids = [i for i in range(1000, 1119, 2)]
# df_ids = pd.DataFrame(ids)
# df_ids.columns = ['ID']

# arr = os.listdir('data/functions')
# df_file = pd.DataFrame(arr)
# df_file.columns = ['FileName']

# df_marks = pd.read_csv('marks/functions_emb_nums.csv', header=None)
# df_marks.columns = ['Marks']

# df_ = pd.concat([df_ids , df_file] , axis=1, join='outer')
# df = pd.concat([df_ , df_marks] , axis=1, join='outer')

# df.to_csv('csvs/combined_data.csv', index=False)

df = pd.read_csv('csvs/combined_data.csv')
display(df,)