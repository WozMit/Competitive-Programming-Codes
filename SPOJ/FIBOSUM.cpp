//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
const ll m = ((ll)1e9)+7ll;

struct matrix{
	int M[3][3];
	matrix(){
		memset(M, 0, sizeof M);
		M[0][0] = M[0][1] = M[1][2] = M[2][1] = M[2][2] = 1;
	}
	matrix I(){
		matrix GG;
		memset(GG.M, 0, sizeof GG.M);
		GG.M[0][0] = GG.M[1][1] = GG.M[2][2] = 1;
		return GG;
	}
	matrix operator *(matrix A)const{
		matrix GG;
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++){
				ll sum = 0ll;
				for(int k=0; k<3; k++) sum = (sum + ((ll)M[i][k]*(ll)A.M[k][j])%m)%m;
				GG.M[i][j] = (int) sum;
			}
		return GG;
	}
};

matrix Exp(matrix A, int b){
	if(!b) return A.I();
	matrix GG = Exp(A, b>>1);
	GG = GG*GG;
	if(b&1) return GG*A;
	return GG;
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te, a, b;
	scanf("%d", &te);
	while(te--){
		scanf("%d %d", &a, &b);
		matrix Ta = Exp(matrix(), a), Tb = Exp(matrix(), b+1);
		int gg = Tb.M[0][2]-Ta.M[0][2];
		while(gg < 0) gg += m;
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
