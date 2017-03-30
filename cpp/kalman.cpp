#include "kalman.h"

kalman::kalman(int ROW, int COL, int itter)
{
	_row = ROW;
	_col = COL;
	_itter = itter;
	initMultiArray(Q, _row, _col);
	initMultiArray(R, _row-1, _col-1);
	init3DArray(Pmin, _row, _col, _itter);
	init3DArray(Pplus, _row, _col, _itter);
	init3DArray(K, _row, _col, _itter);	
	R = initNxNMatrixToEye(_row-1);
	Q = initNxNMatrixToEye(_row-1);
}

void kalman::kalmanFilter()
{
	vector<vector<float> > tmpPmin;
	initMultiArray(tmpPmin, _row, _col);
	
	vector<vector<float> > tmpPplus;
	initMultiArray(tmpPplus, _row, _col);	

	vector<vector<float> > tmpK;
	initMultiArray(tmpK, _row, _col);
	
	for(int i = 1; i < _itter; i++)
	{
		//Pmin[i] = F*Pplus[i-1]*F' + Q
		tmpPmin = matrixAdd(matrixMult(matrixMult(F,tmpPplus),transpose(F)), Q);
		Pmin.push_back(tmpPmin);	
		
		//K[i] = Pmin[i]*H'*inv(H*Pmin[i]*H') + R
		tmpK = matrixAdd(matrixMult(matrixMult(tmpPmin,transpose(H)),matrixInverse(matrixMult(matrixMult(H,tmpPmin),transpose(H)))),R);
		K.push_back(tmpK); 
		
		
		//Pplus = (eye(2) - K(:,:,i)*H)*Pmin(:,:,i);
		tmpPplus = matrixMult(matrixSub(initNxNMatrixToEye(2),matrixMult(tmpK, H)),tmpPmin);
		Pplus.push_back(tmpPplus);
	}
	
}