#include <iostream>
#include <vector>
#include "stdio.h"
#include "kalman.h"

using namespace std;

#define COL 3
#define ROW 3
#define N 144
#define POSTCOVAR 10000

int main()
{
	//kalman circle;
	kalman linear(ROW, COL, N);
    linear.kalmanFilter();
/* Init all our arrays */





}

