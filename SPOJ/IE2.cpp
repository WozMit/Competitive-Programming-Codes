//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int p = (int)1e9+9, MAX = 21;
int n, G[MAX][MAX], A[MAX][MAX], R[MAX][MAX], T[MAX][MAX];

void mul(int M[][MAX]){
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			int sum = 0;
			for(int k=0; k<n; k++) sum = (sum + (ll)M[i][k]*A[k][j]%p)%p;
			T[i][j] = sum;
		}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) M[i][j] = T[i][j];
}

void exp(int b){
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) R[i][j] = (i == j ? 1:0);
	while(b){
		if(b&1) mul(R);
		mul(A);
		b >>= 1;
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int m, k, d;
	while(scanf("%d %d %d %d", &n, &m, &k, &d) == 4){
		while(m--){
			int a, b; scanf("%d %d", &a, &b);
			a--; b--;
			G[a][b] = G[b][a] = 1;
		}
		int gg = (k == 1 && d == 1);
		for(int m=0; m<(1<<k); m++){
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++) A[i][j] = G[i][j];
			for(int i=0; i<k; i++)
				if(m&(1<<i))
					for(int j=0; j<n; j++) A[i][j] = A[j][i] = 0;
			exp(d - 1);
			int sum = 0;
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++) sum = (sum + R[i][j])%p;
			if(__builtin_popcount(m)&1) gg = (gg - sum + p)%p;
			else gg = (gg + sum)%p;
		}
		printf("%d\n", gg);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) G[i][j] = 0;
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
