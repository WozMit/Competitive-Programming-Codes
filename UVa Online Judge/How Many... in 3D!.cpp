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
const int MAX = (int)1e6+5, p = (int)1e9+7;
int dp[MAX], a[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	dp[0] = a[0] = a[1] = 1; dp[1] = 2; dp[2] = 9; a[2] = 3;
	for(int i=3; i<MAX; i++){
		a[i] = (dp[i-1] + a[i-1])%p;
		dp[i] = (((2*dp[i-1])%p + dp[i-2])%p + ((2*a[i-1])%p + (2*a[i-1])%p)%p)%p;
	}
	int te; scanf("%d", &te);
	while(te--){
		int n; scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
