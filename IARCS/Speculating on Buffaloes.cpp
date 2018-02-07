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
const int MAX = 405;
int A[MAX], dp[MAX][MAX], mDif[MAX][MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, k;
	while(scanf("%d %d", &n, &k) == 2){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		for(int i=0; i<n-1; i++){
			mDif[i][i] = 0;
			for(int j=i+1; j<n; j++) mDif[i][j] = max(mDif[i][j-1], A[j] - A[i]);
		}
		for(int pos=0; pos<n; pos++)
			for(int k1=1; 2*k1<=k; k1++){
				int gg = 0;
				for(int i=0; i<pos; i++)
					gg = max(gg, mDif[i][pos] + (i < 1 || k1 == 1 ? 0:dp[i-1][k1-1]));
				dp[pos][k1] = gg;
			}
		printf("%d\n", dp[n-1][k/2]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
