# 生成10000个训练目标
import random as rdm

a = [[0, 0, 1, -1]]
for i in range(1000):
    b = rdm.randrange(-1000, 1000)
    c = rdm.randrange(-1000, 1000)
    if 3 * b + 5 * c > 0:
        a = a + [[b, c, 1, 1]]
    else:
        a = a + [[b, c, 1, -1]]
for i in a:
    print(i)
# 感知机初始化
W = [0.001, 0.002, 0]  # 权重初始化


def y(w, d):
    if w[0] * d[0] + w[1] * d[1] + w[2] > 0:
        e = 1
    else:
        e = -1
    return e


for i in a:
    Y = y(W, i)
    for j in range(2):
        W[j] = W[j] + 0.005 * (i[3] - Y) * i[j]
print(W[1] / W[0])
print(W)

from pylab import *

X1 = []
X2 = []
Y1 = []
Y2 = []
for i in a:
    if i[3] == 1:
        X1 += [i[0]]
        Y1 += [i[1]]
    else:
        X2 += [i[0]]
        Y2 += [i[1]]
scatter(X1, Y1, c='r')
scatter(X2, Y2)
X = np.arange(-1000, 1000, 0.01)
Y = -(W[0] * X + W[2]) / W[1]
print('Y = -{}*X - {}'.format(W[0] / W[1], W[2] / W[1]))
scatter(X, Y, s=0.5)
show()
