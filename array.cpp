#include "array.h"


vector< vector<float> > matrixMult(vector< vector<float> > &a, vector< vector<float> > &b)
{
   vector< vector<float> > tmp;

	int colA = getColSize(a);
	int colB = getColSize(b);

   for(int i = 0; i < a.size(); i++) //rows of a
   {
      for(int j = 0; j < colB; j++) //cols of b
      { 
			for(int k = 0; k < colA; k++) //cols of a
			{
				tmp[i][j] += a[i][k] * b[k][j];
			}
		}
   }
	return tmp;
}

void initNxNMatrixToEye(vector< vector<float> > &a)
{
	int colSize = getColSize(a);
	if(colSize == a.size())
	{
   	for(int i = 0; i < colSize; i++)
		{
			a[i][i] = 1.0;
		}
	}
	else
	{
		std::cout << "Not a NxN matrix... Skipping this function" << std::endl;
	}
}

void initMultiArray(vector< vector<float> > &a, int rSize, int cSize)
{
	a.resize(rSize);
	for(int i = 0; i < rSize; i++)
	{
		a[i].resize(cSize);
	}
}

//This returns the number of vectors in row 0 i.e. num of cols
int getColSize(vector< vector<float> > &a)
{
	return a[0].size();;
}

/*void initNxNMatrixTo1(vector<vector<vector<float>>> a)
{
   for(int i = 0; i < sizeof(a); i++)
	{
		a[i][i][i] = 1;
	}
}*/
