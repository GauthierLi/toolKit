/**test only*/
#include <iostream>
#include <bits/stdc++.h>
#include "headers/dataKit.h"
#include "headers/myMatrix.h"

using namespace std;

vector<vector<float> > getATestMat(){
    //1 0 -1 1 -1 1 0 1 0
    vector<vector<float> > tmp;
    vector<float> tmpV;
    tmpV.push_back(1);
    tmpV.push_back(0);
    tmpV.push_back(-1);
    tmp.push_back(tmpV);
    tmpV.clear();
    tmpV.push_back(1);
    tmpV.push_back(-1);
    tmpV.push_back(1);
    tmp.push_back(tmpV);
    tmpV.clear();
    tmpV.push_back(0);
    tmpV.push_back(1);
    tmpV.push_back(0);
    tmp.push_back(tmpV);
    return tmp;
}

int main()
{
    printf("**************************** DATA_TESTING *****************************\n");
    printf("\n");
    float list1[10] = {1,2,3,4,5,6,7,8,9,10};
    printArr(list1,10);

    int len = sizeof(list1)/sizeof(list1[0]);
    float avrnum = average(list1,len);
    printf("the average num is: %.3f\n", avrnum);
    printf("\n");

    printf("after zero scalar:\n ");
    zscoreScaler(list1, len);
    printArr(list1,len);
    printf("\n");

    printf("after MinMax scalar:\n ");
    minMaxScaler(list1, len);
    printArr(list1,len);
    printf("\n");


    printf("------------------------- read data.csv files -------------------------\n");
    //read csv files and store from the pre_rows to end_rows
    vector<vector<float> > data;
    char *file = (char *)"data.csv";
    readCsv(file, 1, 10, data);
    for(vector<vector<float> >::iterator it1 = data.begin(); it1 != data.end();it1++){
        for(vector<float> :: iterator it = (*it1).begin();it != (*it1).end();it++){
            printf("%.2f ",*it);
        }
        printf("\n");
	}

	printf("-------------------------linear regression ----------------------------\n");
	vector<vector< float> >dataLr;
	float w, b;
	for(int i = 0; i < 5; i++){
        vector<float> tmp;
        tmp.push_back(i);
        tmp.push_back(i+1);
        dataLr.push_back(tmp);
	}
	printVec2D(dataLr);
	OneDlinearRegression(dataLr, &w, &b);
	printf("w: %.2f\nb: %.2f\n",w,b);


    printf("----------------------- matrix test -----------------------------------\n");
/*    myMatrix mat1;
    mat1.setRowandCol(3,3);
    printf("before define matrix\n");
    mat1.printMat();
    printf("please input %d*%d matrix:\n",mat1.row, mat1.col);
    mat1.defMat();
    printf("after define matrix\n");
    mat1.printMat();
    printf("change the row1 ,row3 \n");
    mat1.swapRC(1,3,'r');
    mat1.printMat();
    printf("change the col1 ,col3 \n");
    mat1.swapRC(1,3,'c');
    mat1.printMat();
    printf("add the row2 * 2 to row1 \n");
    mat1.shiftRC(1,2,2,'r');
    mat1.printMat();
    printf("add the col2 * 2 to col1 \n");
    mat1.shiftRC(1,2,2,'c');
    mat1.printMat();
    printf("after transpose\n");
    mat1.trans();
    mat1.printMat();
    printf("\n");
*/

    myMatrix mat2;
    mat2.setRowandCol(3,3);
    printf("please input %d*%d matrix:\n",mat2.row, mat2.col);
    mat2.myMat = getATestMat();

/*    printf("after inverse:\n");
    mat2.inverse();
    mat2.printMat();
    mat1.printMat();

    vector<vector<float> > testVec; //test for cominor
    testVec = mat2.cominor(mat2.myMat,2,2);
    printVec2D(testVec);*/

    printf("test det of:\n");
    mat2.printMat();
    float det = mat2.det(mat2.myMat);
    printf("det of mat2: %.2f\n",det);

    //test for trans_() which return a new 2D vector does not change the origin value of mat
    printVec2D(mat2.trans_());
    mat2.printMat();

    printf("**************************** DATA_TESTING *****************************\n");
    return 0;
}

