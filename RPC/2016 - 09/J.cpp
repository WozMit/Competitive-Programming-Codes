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
int A[500], dp[503][503], n;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t;
	scanf("%d", &t);
	for(int te=0; te<t; te++){
		scanf("%d", &n);
		for(int i=1; i<=n; i++) scanf("%d", &A[i]);
		for(int i=1; i<=n; i++) dp[1][i] = A[1];
		for(int k=1; k<=n; k++)
			for(int i=2; i<=n; i++)
				dp[i][k] = max(A[i]+dp[i-1][min(k-1, i/2-1)], dp[i-1][k]);
		printf("Spree #%d: %d\n", te+1, dp[n][n]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
