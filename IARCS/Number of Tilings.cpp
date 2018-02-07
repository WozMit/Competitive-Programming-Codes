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
const int MAX = (int)1e6+5, mod = (int)1e4;
int dp[MAX], a[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		dp[1] = 1; dp[2] = 2;
		a[0] = a[1] = 0; a[2] = 1;
		for(int i=3; i<=n; i++){
			dp[i] = (dp[i-1] + dp[i-2] + 2*a[i-1])%mod;
			a[i] = (a[i-1] + dp[i-2])%mod;
		}
		printf("%d\n", dp[n]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
