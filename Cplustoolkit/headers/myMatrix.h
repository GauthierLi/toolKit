#ifndef MYMATRIX_H
#define MYMATRIX_H
#include <vector>
using namespace std;

class myMatrix
{
    public:
        vector<vector<float> > myMat;
        int row = 0;
        int col = 0;

        //definite the row and column
        void setRowandCol(int r, int c);
        //print matrix
        void printMat();
        //define the matrix
        void defMat();
        //swap the row and column
        void swapRC(int r, int c, char type/** "r" for row and "c" for col*/);
        //basic shift of matrix
        void shiftRC(int r, int r_, int c, int c_, char type/** "r" for row and "c" for col*/);
        //transpose
        void trans();

        //inverse mat
        vector<vector<float> > inverse();

};

#endif // MYMATRIX_H
