/**test only*/
#include <iostream>
#include <bits/stdc++.h>
#include "dataKit.h"

using namespace std;

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
    printf("**************************** DATA_TESTING *****************************\n");
    return 0;
}