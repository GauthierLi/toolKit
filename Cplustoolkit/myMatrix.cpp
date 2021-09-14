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

void myMatrix::swapRC(int r, int c, char type/** "r" for row and "c" for col*/){
    //swap the row and column
    if(type == 'r'){
        vector<float> tmpVec;
        tmpVec = myMat[r - 1];
        myMat[r - 1] = myMat[c - 1];
        myMat[c - 1] = tmpVec;
    }else if(type == 'c'){
        for(vector<vector<float> >::iterator it = myMat.begin(); it != myMat.end(); it++){
            float tmpF;
            tmpF = (*it)[r - 1];
            (*it)[r - 1] = (*it)[c - 1];
            (*it)[c - 1] = tmpF;
        }
    }
}

void myMatrix::shiftRC(int r, int c, float c_, char type/** "r" for row and "c" for col*/){
    if(r < 1 || r > row || c < 1 || c > col){
        printf("error: please check the value of r or c!\n");
        return;
    }
    if(type == 'r'){
        if(r == c){
            // if r == c ,we define the multipucation of the row
            for(vector<float>::iterator it = myMat[r - 1].begin(), it1 = myMat[c - 1].begin(); it != myMat[r-1].end(); it++,it1++){
                (*it) = (*it) * c_;
            }
            return;
        }
        for(vector<float>::iterator it = myMat[r - 1].begin(), it1 = myMat[c - 1].begin(); it != myMat[r-1].end(); it++,it1++){
            (*it) += (*it1) * c_;
        }
        return;
    }else if(type == 'c'){
        if(r == c){
            for(vector<vector<float> >::iterator it = myMat.begin(); it != myMat.end(); it++){
                (*it)[r - 1] = (*it)[r - 1] * c_;
            }
            return;
        }
        for(vector<vector<float> >::iterator it = myMat.begin(); it != myMat.end(); it++){
            (*it)[r - 1] += (*it)[c - 1] * c_;
        }
        return;
    }
}

void myMatrix::trans(){
    vector<vector<float> >tmp_vec;
    int tmp_int;
    tmp_int = row;
    row = col;
    col = tmp_int;

    for(int i = 0; i < row; i++){
        vector<float> tmp_vec2;
        for(int j = 0; j < col; j++){
            tmp_vec2.push_back(myMat[j][i]);
        }
    tmp_vec.push_back(tmp_vec2);
    }
    myMat = tmp_vec;
}

void myMatrix::inverse(){
    //have some bug, cannot verify whether could it inverse
    if(row != col){
        printf("error : could not inverse!\n");
        return;
    }
    int j = 0;
    for(vector<vector<float> >::iterator it = myMat.begin(); it != myMat.end(); it++){
        for(int i = 0; i < row; i++){
            if(i == j){
                (*it).push_back(1);
            }else{
                (*it).push_back(0);
            }
        }
        j++;
    }
    for(int i = 1; i <= row; i++){
        shiftRC(i, i, 1.0/myMat[i-1][i-1], 'r');
        for(int j = i + 1; j <= row; j++){
            shiftRC(j, i, -myMat[j-1][i-1], 'r');
        }
    }

    for(int i = row; i > 0; i--){
        for(int j = 1; j < i ; j++){
            shiftRC(j, i, -myMat[j-1][i-1], 'r');
        }
    }

    for(int i = 0; i < row; i++){
        vector<float>::iterator it = myMat[i].begin();
        myMat[i].erase(it,it+row);
    }
}
//example could inverse 1 0 -1 1 -1 1 0 1 0

