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
const int MAX = (int)1e3;
int W[MAX], B[MAX], dp[MAX][MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, w;
	while(scanf("%d %d", &n, &w) == 2){
		for(int i=0; i<n; i++) scanf("%d %d", &W[i], &B[i]);
		for(int i=0; i<n; i++)
			for(int wg=1; wg<=w; wg++){
				int gg = i ? dp[i-1][wg]:0;
				if(W[i] <= wg) gg = max(gg, B[i]+(i ? dp[i-1][wg-W[i]]:0));
				dp[i][wg] = gg;
			}
		printf("%d\n", dp[n-1][w]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
