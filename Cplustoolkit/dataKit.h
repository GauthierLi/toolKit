#ifndef DATAKIT_H_INCLUDED
#define DATAKIT_H_INCLUDED

#include <vector>
using namespace std;

/** print vector */
void printVec(vector<float> vec);

/** print list arrary*/
void printArr(float *p1, int len);

/** calculate the average of the list*/
float average(float *p1, int len);

/**standardization for 0 mean, 1 var*/
int zscoreScaler(float *p1, int len);

/** standardization the date between 0 and 1 */
int minMaxScaler(float *p1, int len);

/**Find minimum num, 0 represent minimum, 1 represent maximum.*/
float findMinMax(float *p1, int len, int n);


/**read csv as a matrix*/
void readCsv(char *fileName,int line_pre, int line_end, vector<vector<float> > &data/**out*/);

#endif // DATAKIT_H_INCLUDED
