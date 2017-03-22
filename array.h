#include <iostream>
#include <vector>
#include <exception>
#include "stdio.h"

using std::vector;

#ifndef ARRAY_H
#define ARRAY_H
vector< vector<float> > matrixMult(vector< vector<float> > &a, vector< vector<float> > &b);
void initNxNMatrixToEye(vector< vector<float> > &a);
void initMultiArray(vector< vector<float> > &a, int rSize, int cSize);
int getColSize(vector< vector<float> > &a);
#endif
