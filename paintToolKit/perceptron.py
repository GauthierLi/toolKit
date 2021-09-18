import numpy as np
import random
import paint
import matplotlib.pyplot as plt

random.seed()


class node(object):
    """docstring for node"""
    def __init__(self, n):
        # the num of weight
        self.n = n
        self.input = []
        self.output = 0
        self.weightArr = []
        for i in range(self.n):
            # init the weight vector and input vector
            tmp = random.random()
            self.weightArr.append(tmp)
            self.input.append(tmp)

    def inputAndOutput(self, list):
        '''
            this list was inputs of the node,which the lenth is the same as the weight
        '''
        self.input = list
        self.caculate()
        print("the output is: %.3f" % self.output)

    def caculate(self):
        self.output = 0
        for i in range(self.n):
            self.output = self.output + self.input[i] * self.weightArr[i]
        return self.output

    def learnOnece(self, list1, yita=0.02):
        '''
            the list1 was composed with the input num and the torture signal at the end
        '''
        for i in range(self.n):
            self.input[i] = list1[i]
        self.caculate()

        if len(list1) != len(self.input) + 1:
            print(len(list1) - len(self.input) - 1)
            print("error: the len of list does not match the lenth of input!")
            return

        error = self.output - list1[-1]
        for i in range(self.n):
            self.weightArr[i] -= yita * error * self.input[i]

    def learning(self, time, list, yita=0.02):
        '''
            this list was conposed with many members of basic signal
        '''
        for i in range(time):
            for j in list:
                self.learnOnece(j, yita)


if __name__ == "__main__":
    nnode = node(2)
    '''
    # test only
    print(nnode.weightArr)
    nnode.inputAndOutput([1,1])
    nnode.learnOnece([-1,1,0])
    '''
    list = [[-1.1, 1, 0.2], [-0.5, 1, 0.55], [0.07, 1, 1.112], [1.1, 1, 1.98], [0.515, 1, 1.5], [-0.501, 1, 0.488], [0.2, 1, 1.05], [0.89, 1, 1.996],
            [0.5, 1, 1.5], [-1, 1, 0]]
    nnode.learning(100, list)
    print(nnode.weightArr)

    xlist = []
    ylist = []
    for i in list:
        xlist.append(i[0])
        ylist.append(i[2])
    paint.draw(xlist, ylist, "perceptron","scatter")

    nxlist = paint.despPoint(-1,1)
    nylist = [nnode.weightArr[0] * i + nnode.weightArr[1] for i in nxlist]
    paint.draw(nxlist, nylist, "perceptron")
    plt.show()