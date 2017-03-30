#include <iostream>
#include <vector>
#include "matrixFunctions.h"

#ifndef KALMAN_H
#define KALMAN_H

class kalman : public matrixFunctions
{
	public:
		kalman (int ROW, int COL, int itter);
		void kalmanFilter();
	private:
		int _row;
		int _col;
		int _itter;
		vector<vector<float> > Q;
		vector<vector<float> > R;

		vector<vector<float> > x; //3xN
		vector<vector<float> > y; //2xN
		vector<vector<float> > u; //2xN	
		vector<vector<float> > xhatM; //3xN
		vector<vector<float> > xhatP; //3xN

		vector<vector<float> > F; //3x3
		vector<vector<float> > G; //3x3
		vector<vector<float> > H; //3x2

/* Define our 3D Arrays */
		vector<vector<vector<float> > > Pmin; //3x3xN
		vector<vector<vector<float> > > Pplus; //3x3xN
		vector<vector<vector<float> > > K; //3x2xN
	
	
	
};
#endif