#include <bits/stdc++.h>
using namespace std;

const int max_n = 2;
struct Matrix{
	int M[max_n][max_n];
};

Matrix MatMult(Matrix A, Matrix B){
	Matrix ans;
	int i, j, k;
	for(i=0; i<max_n; i++)
		for(j=0; j<max_n; j++)
			for(ans.M[i][j] = k = 0; k<max_n; k++)
				ans.M[i][j] += A.M[i][k]*B.M[k][j];
	return ans;
}

Matrix Exp(Matrix A, int exP){
	if(exP == 1) return A;
	Matrix ans = Exp(A, exP>>1);
	ans = MatMult(ans, ans);
	if(exP&1) return MatMult(ans, A);
	return ans;
}

int main() {
	Matrix A;
	A.M[0][0] = 0;
	A.M[0][1] = A.M[1][0] = A.M[1][1] = 1;
	A = Exp(A, 13);
	for(int i=0; i<max_n; i++){
		for(int j=0; j<max_n; j++) cout << A.M[i][j] << " ";
		cout << endl;
	}
	return 0;
}