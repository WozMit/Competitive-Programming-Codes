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
const int MAX = 253, oo = 1<<30;
int n, F[MAX], bit[MAX], dp[MAX][MAX];

int Sol(int i, int j){
	if(i >= j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int gg = oo, sum = bit[j]-(i ? bit[i-1]:0);
	for(int r=i; r<=j; r++)
		gg = min(gg, sum-F[r]+Sol(i, r-1)+Sol(r+1, j));
	return dp[i][j] = gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d", &n) == 1){
		memset(dp, -1, sizeof dp);
		for(int i=0; i<n; i++){
			scanf("%d", &F[i]);
			bit[i] = F[i] + (i ? bit[i-1]:0);
		}
		printf("%d\n", Sol(0, n-1));
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
