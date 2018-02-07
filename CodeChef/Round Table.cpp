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
const int MAX = (int)1e6+5;
int A[MAX], n, dp[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		dp[0] = A[0]; dp[1] = A[1];
		for(int i=2; i<n; i++) dp[i] = A[i] + min(dp[i-1], dp[i-2]);
		int gg = dp[n-1];
		reverse(A, A+n);
		dp[0] = A[0]; dp[1] = A[1];
		for(int i=2; i<n; i++) dp[i] = A[i] + min(dp[i-1], dp[i-2]);
		gg = min(gg, dp[n-1]);
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
