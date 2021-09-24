# toolKit

​    自己制作的一些工具包，方便建模比赛调用或学习

# Cplustoolkit

## datakit.h

- ```c++
  void printVec2D(vector<vector<float> > vec);
  void printVecOneD(vector<float> vec);
  ```

  打印一维、二维`vector`

  

- ``` c++
  void printArr(float *p1, int len);
  ```

  打印一维数组



- ```c++
  float average(float *p1, int len);
  ```

  计算均值，传入数组，数组长度



- ``` c++
  int zscoreScaler(float *p1, int len);
  ```

  将数组 0-1 标准化



- ```c++
  int minMaxScaler(float *p1, int len);
  ```

  将数组放缩到 $[0,1]$ 内标准化



- ```c++
   float findMinMax(float *p1, int len, int n);
  ```

  返回数组最大值或最小值，n 取0 返回最小值， 1 返回最大值



- ```c++
  void readCsv(char *fileName,int line_pre, int line_end, vector<vector<float> > &data);
  ```

  读取csv文件的第 line_pre 行到 line_end 行，将其储存在data中



- ``` c++
  void OneDlinearRegression(vector<vector<float> >data, float *w, float *b);
  ```

  二维线性回归，斜率储存在w 中， 截距储存在 b中

## myMatrix.h

​    所有的函数没有加 `_` 的表示改变原矩阵，加了的表示返回一个新的二维向量，需要用一个二维 `vector` 接受返回值

```c++
class myMatrix
{
    public:
        vector<vector<float> > myMat;
        int row = 0;
        int col = 0;

        void getRowandCol();
        //definite the row and column
        void setRowandCol(int r, int c);
        //print matrix
        void printMat();
        //define the matrix
        void defMat();
        //swap the row and column
        void swapRC(int r, int c, char type/** "r" for row and "c" for col*/);
        //the bar '_' means which does not change the value of origin mat vector,and return the result
        vector<vector<float> > swapRC_(int r, int c, char type/** "r" for row and "c" for col*/);
        //basic shift of matrix,add c*c_ to r
        void shiftRC(int r, int c, float c_, char type/** "r" for row and "c" for col*/);
        vector<vector<float> > shiftRC_(int r, int c, float c_, char type/** "r" for row and "c" for col*/);
        //transpose
        void trans();
        vector<vector<float> > trans_();
        //inverse mat
        void inverse();
        vector<vector<float> > inverse_();
        vector<vector<float> > mul(vector<vector<float> > mat);


        //get the cominor
        vector<vector<float> > cominor(vector<vector<float> > nmat,int r, int c);
        //get the determinant
        float det(vector<vector<float> > mat);

};
```

# paintToolKit

​	用python写的一个画图工具

## paint.py

- ```python
  def draw(list1, list2, myLabel, type="aaa")

list1是 x坐标， list2 是 y 坐标, myLabel 是自定义图标名称，type为画图形式， 默认连续图， "scatter"为散点图

- ``` python
  def despPoint(start, end, step=0.01)

将区间离散化，步长默认0.01

