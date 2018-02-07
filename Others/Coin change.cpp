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
const int MAX = 150;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, k, C[MAX], dp[MAX];
	while(scanf("%d %d", &n, &k) == 2){
		for(int i=0; i<k; i++) scanf("%d", &C[i]);
		dp[0] = 0;
		for(int j=1; j<=n; j++) dp[j] = 1<<30;
		for(int i=0; i<k; i++)
			for(int j=1; j<=n; j++) dp[j] = min(dp[j], j >= C[i] ? (1+dp[j-C[i]]):(1<<30));
		printf("%d\n", dp[n]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
