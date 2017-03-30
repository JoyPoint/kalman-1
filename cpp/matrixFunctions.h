#include <iostream>
#include <vector>
#include "stdio.h"

using  std::vector;

#ifndef MATRIX_FUNC_H
#define MATRIX_FUNC_H

class matrixFunctions 
{
	public:
		matrixFunctions();
		void initMultiArray(vector< vector<float> > a, int rSize, int cSize);
		void init3DArray(vector< vector< vector<float> > > a, int rSize, int cSize, int zSize);		
		vector< vector<float> > initNxNMatrixToEye(int size);
		vector< vector<float> > matrixMult(vector< vector<float> > a, vector< vector<float> > b);
		vector< vector<float> > transpose(vector< vector<float> > a);
		vector< vector<float> > matrixAdd(vector< vector<float> > a, vector< vector<float> > b);
		vector< vector<float> > matrixSub(vector< vector<float> > a, vector< vector<float> > b);		
		vector< vector<float> > matrixInverse(vector< vector<float> > a);
		vector< vector<float> > eyeMatrix(int size);
		void adjoint(vector< vector<float> > a, vector< vector<float> > adj, vector< vector<float> > tmp);
		int determinant(vector< vector<float> > detM, int n);
		void getCofactor(vector< vector<float> > a, vector< vector<float> > tmp, int p, int q, int n);		
	private:
		int getColSize(vector< vector<float> > a);


};
#endif
