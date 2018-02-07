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
const int MAX = (int)2e5+5;
int A[MAX], dp[MAX][4];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		dp[0][0] = dp[0][1] = 0;
		dp[0][2] = A[0];
		for(int i=1; i<n; i++){
			for(int count = 0; count < 2; count++)
				dp[i][count] = min(dp[i-1][count+1], A[i] + dp[i-1][0]);
			dp[i][2] = A[i] + dp[i-1][0];
		}
		printf("%d\n", dp[n-1][0]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
