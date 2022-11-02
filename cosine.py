from sklearn.metrics import pairwise
from scipy import spatial


X = ['alishbah']

Y = ['alishbah']




# s = pairwise.cosine_similarity(X, Y=None, dense_output=True)

# print('SIM = ', s)

result = 1 - spatial.distance.cosine(X, Y)
print('result = ', result)