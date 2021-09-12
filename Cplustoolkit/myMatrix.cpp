#include "headers/myMatrix.h"
#include "headers/dataKit.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

//definite the row and column
void myMatrix::setRowandCol(int r, int c){
    row = r;
    col = c;
}

void myMatrix::printMat(){
    printf("row: %d\ncol: %d\n",row, col);
    printVec2D(myMat);
}

void myMatrix::defMat(){
    if(row == 0 || col == 0){
        printf("error: error matrix with 0 row or 0 col");
        return;
    }
    for(int i = 0; i < row; i++){
        vector<float> tmpVec;
        for(int j = 0; j < col; j++){
            float tmp;
            cin >> tmp;
            tmpVec.push_back(tmp);
        }
        myMat.push_back(tmpVec);
    }
}
