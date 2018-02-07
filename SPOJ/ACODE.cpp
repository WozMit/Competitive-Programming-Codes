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

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	char A[5007];
	ll dp[5007];
	while(gets(A) && A[0] != '0'){
		dp[0] = dp[1] = 1ll;
		int n = strlen(A);
		for(int i=2; i<=n; i++){
			dp[i] = A[i-1]-'0' ? dp[i-1]:0ll;
			if(A[i-2]-'0' && 10*(A[i-2]-'0') + (A[i-1]-'0') < 27) dp[i] += dp[i-2];
		}
		printf("%lld\n", dp[n]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
