#include "array.h"



vector< vector<float> > arrayFunc::matrixMult(vector< vector<float> > a, vector< vector<float> > b)
{
   vector< vector<float> > tmp;

	int colA = 0;
	int colB = 0;

	for(int z = 0; z < a.size(); z++)
	{
   	colA += a[z].size();
	}
	for(int z = 0; z < a.size(); z++)
	{
   	colB += b[z].size();
	}

   for(int i = 0; i < a[0].size(); i++) //rows of a
   {
      for(int j = 0; j < sizeof(b); j++) //cols of b
      { 
			for(int k = 0; k < sizeof(b); k++) //cols of a
			{
				tmp[i][j] += a[i][k] * b[k][j];
			}
		}
   }
	return tmp;
}

void arrayFunc::initNxNMatrixToEye(vector< vector<float> > a)
{
   for(int i = 0; i < sizeof(a); i++)
	{
		a[i][i] = 1.0;
	}
}

void arrayFunc::initMultiArray(vector< vector<float> > a, int rSize, int cSize)
{
	a.resize(cSize);
	for(int i = 0; i < cSize; i++)
	{
		a[i].resize(rSize);
	}
}


/*void initNxNMatrixTo1(vector<vector<vector<float>>> a)
{
   for(int i = 0; i < sizeof(a); i++)
	{
		a[i][i][i] = 1;
	}
}*/
