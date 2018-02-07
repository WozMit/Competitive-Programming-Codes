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
const int MAX = (int)1e4+7;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t, n, A[MAX];
	ll dp[MAX];
	scanf("%d", &t);
	for(int t1=0; t1<t; t1++){
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		dp[0] = A[0];
		dp[1] = max(A[0], A[1]);
		for(int i=2; i<n; i++) dp[i] = max(A[i]+dp[i-2], dp[i-1]);
		printf("Case %d: %lld\n", t1+1, dp[n-1]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
