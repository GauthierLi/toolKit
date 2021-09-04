#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "dataKit.h"

using namespace std;


void printVec(vector<float> vec){
    /** print vector */
    for(vector<float>::iterator it = vec.begin(); it != vec.end(); it++){
        printf("%.2f ",*it);
    }
    printf("\n");
}

void printArr(float *p1, int len){
    /**��ӡ�б�*/
    for(int i = 0; i < len; i++){
        printf("%.3f ", p1[i]);
    }
    printf("\n");
}

float average(float *p1, int len){
    /**���ֵ*/
    if(p1 == NULL){
        printf("error -1 : Null point!!!");
        return -1;
    }

    if(len == 0){
        return 0;
    }

    float avr = 0;
    for(int i = 0; i < len; i++){
        avr += p1[i];
    }
    return avr / len;
}

int zscoreScaler(float *p1, int len){
    /**0��ֵ��׼��*/
    if(p1 == NULL){
        printf("error -1: Null point!!!");
        return -1;
    }

    if(len == 0){
        printf("error -2: lenth is 0!!!");
        return -2;
    }

    float avr = average(p1, len);

    float avrSquar = 0;
    for(int i = 0; i < len; i++){
        avrSquar += (p1[i] - avr)*(p1[i] - avr);
    }
    avrSquar = avrSquar/len;
    avrSquar = sqrt(avrSquar);

    for(int i = 0; i < len; i++){
        p1[i] = (p1[i] - avr)/avrSquar;
    }
    return 0;
}

float findMinMax(float *p1, int len , int n){
    /**Find minimum num, 0 represent minimum, 1 represent maximum.*/
    float Mini = p1[0];
    float Maxi = p1[0];

    for(int i = 0; i < len ; i++){
        if(Mini > p1[i]) Mini = p1[i];
        if(Maxi < p1[i]) Maxi = p1[i];
    }

    if(n == 0){
        return Mini;
    }else if(n == 1){
        return Maxi;
    }else{
        printf("error : please input right indication number!");
        return -99999999999;
    }
}


int minMaxScaler(float *p1, int len){
    /** ����׼����������0-1 */
    if(p1 == NULL){
        printf("error -1: Null point!!!");
        return -1;
    }

    if(len == 0){
        printf("error -2: lenth is 0!!!");
        return -2;
    }
    float minimum = findMinMax(p1, len, 0);
    float maximum = findMinMax(p1, len, 1);

    if(minimum == maximum){
        for(int i =0; i < len ;i++){
            p1[i] = 1;
        }
    }

    for(int i = 0; i <len; i++){
        p1[i] = (p1[i] - minimum) / (maximum - minimum);
    }
    return 0;
}


void readCsv(char *fileName,int line_pre, int line_end, vector<vector<float> > &data/**out*/){
    /**read csv as a matrix*/
    ifstream inFile(fileName, ios::in);
	string lineStr;
	vector<vector<string> > strArray;
	while (getline(inFile, lineStr))
	{
        stringstream ss(lineStr);
        string str;
        vector<string> lineArray;
        while(getline(ss, str,',')){
            lineArray.push_back(str);
        }
        strArray.push_back(lineArray);
	}

/*
	for(vector<vector<string> >::iterator it1 = strArray.begin(); it1 != strArray.end();it1++){
        for(vector<string> :: iterator it = (*it1).begin();it != (*it1).end();it++){
            cout << *it << " ";
        }
        cout <<endl;
	}
*/


    for(int i = line_pre; i < line_end; i++){
        vector<float> tmp_vec;
        for(vector<string> ::iterator it = strArray[i].begin(); it != strArray[i].end(); it++){
            stringstream stream;
            float tmp = 0.0;
            stream << *it;
            stream >> tmp;
            tmp_vec.push_back(tmp);
        }
        data.push_back(tmp_vec);
    }

}

