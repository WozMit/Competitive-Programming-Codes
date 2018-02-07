#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int max_n = 2;

struct Matrix{	ll M[max_n][max_n];	};

Matrix MatMult(Matrix A, Matrix B){
	Matrix ans;
	int i, j, k;
	for(i=0; i<max_n; i++)
		for(j=0; j<max_n; j++)
			for(ans.M[i][j] = k = 0; k<max_n; k++)
				ans.M[i][j] += A.M[i][k]*B.M[k][j];
	return ans;
}

Matrix Exp(Matrix A, ll exP){
	if(exP == 1) return A;
	Matrix ans = Exp(A, exP>>1);
	ans = MatMult(ans, ans);
	if(exP&1) return MatMult(ans, A);
	return ans;
}

int main() {
	ll p, q, n;
	Matrix T, GG;
	T.M[0][0] = 0;
	T.M[0][1] = 1;
	while(cin >> p >> q >> n && !(p == 0 && q == 0 && n == 0)){
		if (n == 0) cout << 2 << endl;
		else{
			T.M[1][0] = -q;
			T.M[1][1] = p;
			GG = Exp(T, n);
			cout << (GG.M[0][0]*2+GG.M[0][1]*p) << endl;
		}
	}
	return 0;
}