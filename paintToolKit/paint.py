# _*_ encoding:utf-8 _*_
"""
author: Gauthier
date  :2021/09/12
"""
import matplotlib.pyplot as plt
import numpy as np


def draw(list1, list2, myLabel, type="aaa"):
    '''

    :param list1: x axe
    :param list2: y axe
    :param myLabel: legend
    :param type: "scatter" for scatter, default for line
    :return:need to plt.show()
    '''
    if (len(list1) != len(list2)):
        print("error: the lenth of two list are notequal!")
        return
    if type == "scatter":
        plt.scatter(list1, list2, alpha=0.3)
    else:
        plt.plot(list1, list2, label=myLabel)


def despPoint(start, end, step=0.01):
    """

    :param start: start of list
    :param end: end of list
    :param step: step of list
    :return: list but  LOSS OF ACCURACY
    """
    tmp = []
    for i in np.arange(start, end, step):
        tmp.append(i)
    return tmp


if __name__ == '__main__':
    l1 = despPoint(1, 11, 1)
    l2 = despPoint(4, 14, 1)

    draw(l1, l2, 'pic1')
    plt.show()
