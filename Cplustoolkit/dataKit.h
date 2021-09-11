#ifndef DATAKIT_H_INCLUDED
#define DATAKIT_H_INCLUDED

#include <vector>
using namespace std;

/** print 1D,2D vector */
void printVecOneD(vector<float> vec);
void printVec2D(vector<vector<float> > vec);

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

/** get the parametres of linear regression*/
void OneDlinearRegression(vector<vector<float> >data, float *w/** out */, float *b/** out */);


#endif // DATAKIT_H_INCLUDED
