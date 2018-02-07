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
const int MAX = 507, inf = 1<<30;
int A[MAX], dp[MAX][MAX];

int Sol(int i, int j){
	if(i == j) return 1;
	if(i > j) return inf;
	if(dp[i][j] != -1) return dp[i][j];
	int gg = inf;
	if(A[i] == A[j]){
		if(i+1 == j) return 1;
		gg = min(gg, Sol(i+1, j-1));
	}
	for(int k=i; k<j; k++) gg = min(gg, Sol(i,k)+Sol(k+1,j));
	return dp[i][j] = gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		for(int i=0; i<=n; i++)
			for(int j=0; j<=n; j++) dp[i][j] = -1;
		printf("%d\n", Sol(0, n-1));
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s";
	#endif
	return 0;
}
