#include <iostream>
#include <vector>
#include "stdio.h"

#define COL 3
#define ROW 3
#define N 144
#define POSTCOVAR 10000

class arrayFunc
{

	public:
		arrayFunc();
		void initMultiArray(vector< vector<float> > a, int rSize, int cSize);
		void initNxNMatrixToEye(vector< vector<float> > a);
		vector< vector<float> > matrixMult(vector< vector<float> > a, vector< vector<float> > b);


};
