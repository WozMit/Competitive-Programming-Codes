//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
typedef long long int ll;
ll n, b, gg;
struct Matrix{ ll M[3][3]; };

Matrix Mult(Matrix A, Matrix B){
	Matrix GG;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++){
			GG.M[i][j] = 0;
			for(int k=0; k<3; k++)
				GG.M[i][j] += ((A.M[i][k]%b) * (B.M[k][j]%b))%b;
			GG.M[i][j] %= b;
		}
	return GG;
}

Matrix Exp(Matrix A, ll e){
	if(e == 1) return A;
	Matrix GG = Exp(A, e>>1);
	GG = Mult(GG, GG);
	if(e&1) return Mult(GG, A);
	return GG;
}

int main() {
	int casE = 0;
	Matrix T;
	while(1){
		scanf("%lld%lld", &n, &b);
		if(n == 0 && b == 0) break;
		T.M[0][0] = T.M[0][2] = T.M[2][0] = T.M[2][1] = 0;
		T.M[0][1] = T.M[1][0] = T.M[1][1] = T.M[1][2] = T.M[2][2] = 1;
		if(n == 0 || n == 1) gg = 1;
		else{
			T = Exp(T, n);
			gg = (T.M[0][0]+T.M[0][1]+T.M[0][2])%b;
		}
		printf("Case %d: %lld %lld %lld\n", ++casE, n, b, gg);
	}
	return 0;
}