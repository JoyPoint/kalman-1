#include "matrixFunctions.h"

matrixFunctions::matrixFunctions()
{

}

void matrixFunctions::initMultiArray(vector< vector<float> > a, int rSize, int cSize)
{
	a.resize(cSize);
	for(int i = 0; i < cSize; i++)
	{
		a[i].resize(rSize);
	}
}

void matrixFunctions::init3DArray(vector< vector< vector<float> > >a, int rSize, int cSize, int zSize)
{
	a.resize(cSize);
	for(int i = 0; i < cSize; i++)
	{
		a[i].resize(rSize);
		for(int j = 0; j < rSize; j++)
		{
			a[i][j].resize(zSize);
		}
	}
}


vector< vector<float> > matrixFunctions::matrixMult(vector< vector<float> > a, vector< vector<float> > b)
{
   vector< vector<float> > tmp;

	int colA = 0;
	int colB = 0;
	colA = getColSize(a);
	colB = getColSize(b);
	
   for(int i = 0; i < a[0].size(); i++) //rows of a
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

vector< vector<float> > matrixFunctions::matrixAdd(vector< vector<float> > a, vector< vector<float> > b)
{
    vector< vector<float> > tmp;
	int colA = 0;
	int colB = 0;

	colA = getColSize(a);
	colB = getColSize(b);
	for(int i = 0; i < colA; i++) //col of a
	{
		for(int j = 0; j < a[0].size(); j++) //rows of a
		{	 
			tmp[i][j] = a[i][j] + b[i][j];
		}
	}
	return tmp;
}

vector< vector<float> > matrixFunctions::matrixSub(vector< vector<float> > a, vector< vector<float> > b)
{
    vector< vector<float> > tmp;
	int colA = 0;
	int colB = 0;

	colA = getColSize(a);
	colB = getColSize(b);
	for(int i = 0; i < colA; i++) //col of a
	{
		for(int j = 0; j < a[0].size(); j++) //rows of a
		{	 
			tmp[i][j] = a[i][j] - b[i][j];
		}
	}
	return tmp;
}

vector< vector<float> > matrixFunctions::initNxNMatrixToEye(int size)
{
	vector< vector<float> > a;
	initMultiArray(a,size,size);
	for(int i = 0; i < sizeof(a); i++)
	{
		a[i][i] = 1.0;
	}
	return a;
}

vector< vector<float> > matrixFunctions::transpose(vector< vector<float> > a)
{
	int r = a[0].size();
	int c = getColSize(a);	
	vector< vector<float> > tmp;
	
	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
        {
            tmp[j][i]=a[i][j];
        }
	}
	return tmp;
}

/*void matrixFunctions::initNxNMatrixTo1(vector< vector< vector<float> > > a)
{
   for(int i = 0; i < sizeof(a); i++)
	{
		a[i][i][i] = 1;
	}
}*/

int matrixFunctions::getColSize(vector< vector<float> > a)
{
	int colSize = 0;
	
	for(int z = 0; z < a.size(); z++)
	{
   	colSize += a[z].size();
	}	
	return colSize;
}


vector< vector<float> > matrixFunctions::matrixInverse(vector< vector<float> > a)
{
	int r = a[0].size();
	int c = getColSize(a);
	vector< vector<float> > inv;
	initMultiArray(inv, r, c);	
	
    // Find determinant of a
    int det = determinant(a, r);
    if (det == 0)
    {
        std::cout << "Singular matrix, can't find its inverse" << std::endl;
    }
	else
	{
		// Find adjoint
		vector< vector<float> > adj;
		vector< vector<float> > tmp;
		initMultiArray(adj, r, c);
		initMultiArray(tmp, r, c);	
		adjoint(a, adj, tmp);
 
		// Find Inverse using formula "inverse(A) = adj(A)/det(A)"
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				inv[i][j] = adj[i][j]/float(det);
	}
	return inv;
}

void matrixFunctions::adjoint(vector< vector<float> > a, vector< vector<float> > adj, vector< vector<float> > tmp)
{
    if (a[0].size() == 1)
    {
        a[0][0] = 1;
        return;
    }
 
	int N = getColSize(a);
    // temp is used to store cofactors of A[][]
    int sign = 1;

    for (int i=0; i < a[0].size(); i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Get cofactor of A[i][j]
            getCofactor(a, tmp, i, j, N);
 
            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;
 
            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            a[j][i] = (sign)*(determinant(tmp, N-1));
        }
    }
}

int matrixFunctions::determinant(vector< vector<float> > detM, int n)
{
    int D = 0; // Initialize result
 
    //  Base case : if matrix contains single element
    if (n == 1)
        return detM[0][0];
 
    vector< vector<float> > temp; // To store cofactors
	initMultiArray(temp, detM[0].size(), getColSize(detM));	
 
    int sign = 1;  // To store sign multiplier
 
     // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of A[0][f]
        getCofactor(detM, temp, 0, f, n);
        D += sign * detM[0][f] * determinant(temp, n - 1);
 
        // terms are to be added with alternate sign
        sign = -sign;
    }
 
    return D;
}

void matrixFunctions::getCofactor(vector< vector<float> > a, vector< vector<float> > tmp, int p, int q, int n)
{
    int i = 0, j = 0;
 
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                tmp[i][j++] = a[row][col];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}