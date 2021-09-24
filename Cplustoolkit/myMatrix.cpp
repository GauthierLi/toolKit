#include "headers/myMatrix.h"
#include "headers/dataKit.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void myMatrix::getRowandCol(){
    row = myMat.size();
    col = myMat[0].size();
}

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
    getRowandCol();
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

vector<vector<float> > myMatrix::swapRC_(int r, int c, char type){
    vector<vector<float> > oriVec,tmpVec;
    oriVec = myMat;
    swapRC(r,c,type);
    tmpVec = myMat;
    myMat = oriVec;
    return tmpVec;
}

void myMatrix::shiftRC(int r, int c, float c_, char type/** "r" for row and "c" for col*/){
    getRowandCol();
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

vector<vector<float> > myMatrix::shiftRC_(int r,int c, float c_,char type){
    vector<vector< float> > oriVec, tmpVec;
    oriVec = myMat;
    shiftRC(r,c,c_,type);
    tmpVec = myMat;
    myMat = oriVec;
    return tmpVec;
}

void myMatrix::trans(){
    getRowandCol();
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

vector<vector<float> > myMatrix::trans_(){
    vector<vector<float> > oriVec,tmpVec;
    oriVec = myMat;
    trans();
    tmpVec = myMat;
    myMat = oriVec;
    return tmpVec;
}

void myMatrix::inverse(){
    getRowandCol();
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

vector<vector<float> > myMatrix::inverse_(){
    vector<vector<float> > oriVec, tmpVec;
    oriVec = myMat;
    inverse();
    tmpVec = myMat;
    myMat = oriVec;
    return tmpVec;
}

vector<vector<float> > myMatrix::cominor(vector<vector<float> > nmat, int r, int c){
    nmat.erase(nmat.begin() + r - 1);
    for(vector<vector<float> >::iterator it = nmat.begin();it != nmat.end();it++){
        (*it).erase((*it).begin() + c - 1);
    }
    return nmat;
}


float myMatrix::det(vector<vector<float> >mat){
    if(mat.size() == 1){
        return mat[0][0];
    }
    vector<vector<float> > nMat;
    nMat = mat;
    float result = 0.0;
    for(int i = 0; i < nMat[0].size();i++){
        result += pow(-1,i) * nMat[0][i] * det(cominor(mat,1,i+1));
    }
    return result;
}

vector<vector<float> > myMatrix::mul(vector<vector<float> > mat){
    getRowandCol();
    vector<vector<float> > result;
    int r = row;
    int c = mat[0].size();
    if(col != mat.size()){
        printf("error : the row of mymat does not match the target col!\n");
    }

    for(int i = 0; i < r; i++){
        vector<float> tmpVec;
        for(int j = 0; j < c; j++){
            float tmp_f = 0;
            for(int k = 0; k < col ;k++){
                tmp_f += myMat[i][k] * mat[k][j];
            }
            tmpVec.push_back(tmp_f);
        }
        result.push_back(tmpVec);
    }

    return result;
}
