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
const ll m = 1000000009;
struct Matrix{ ll M[3][3]; };

Matrix Prod(Matrix A, Matrix B){
	Matrix GG;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++){
			GG.M[i][j] = 0ll;
			for(int k=0; k<3; k++)
				GG.M[i][j] += ((A.M[i][k])%m * (B.M[k][j])%m)%m;
			GG.M[i][j] %= m;
		}
	return GG;
}

Matrix Exp(Matrix A, ll e){
	if(e == 1) return A;
	Matrix GG = Exp(A, e>>1ll);
	GG = Prod(GG, GG);
	if(e&1ll) return Prod(GG, A);
	return GG;
}

int main() {
	ll n, gg;
	map<ll, ll> memo;
	Matrix T;
	while(scanf("%lld", &n) == 1 && n){
		if(n<3) gg = n-1ll;
		else if(memo.count(n)) gg = memo[n];
		else{
			T.M[0][0] = T.M[0][2] = T.M[1][0] = T.M[1][1] = 0;
			T.M[0][1] = T.M[1][2] = T.M[2][0] = T.M[2][1] = T.M[2][2] = 1;
			T = Exp(T, n-1);
			gg = memo[n] = (T.M[0][1]%m + (T.M[0][2]*2ll)%m)%m;
		}
		printf("%lld\n", gg);
	}
	return 0;
}