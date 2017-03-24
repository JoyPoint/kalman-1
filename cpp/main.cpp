#include <iostream>
#include <vector>
#include "stdio.h"
#include "array.h"

using namespace std;

#define COL 3
#define ROW 3
#define N 144
#define POSTCOVAR 10000

int main()
{
/* Define our 2D Arrays */
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

/* Init all our arrays */
	initMultiArray(Q, ROW, COL);
	initMultiArray(R, ROW-1, COL-1);
	initNxNMatrixToEye(R);
	initNxNMatrixToEye(Q);


   cout << "Number of vectors in Q: " << Q.size() << endl;	
   cout << "Number of vectors in R: " << R.size() << endl;


}

