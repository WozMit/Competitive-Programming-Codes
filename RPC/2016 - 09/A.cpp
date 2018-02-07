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
ll dp[103];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t, n, C[10];
	dp[0] = 1;
	scanf("%d", &t);
	for(int te=0; te<t; te++){
		for(int i=0; i<8; i++) scanf("%d", &C[i]);
		scanf("%d", &n);
		for(int i=1; i<=n; i++) dp[i] = 0;
		for(int i=0; i<8; i++)
			for(int j=C[i]; j<=n; j++) dp[j] += dp[j-C[i]];
		printf("Equation #%d: %lld\n", te+1, dp[n]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
