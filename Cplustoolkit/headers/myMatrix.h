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


#endif // MYMATRIX_H
