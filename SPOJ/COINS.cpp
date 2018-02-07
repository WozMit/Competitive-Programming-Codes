//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <map>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = (int)1e7;
map<int, ll> M;
int dp[MAX];

ll Solve(int n){
	if(n < MAX) return dp[n];
	if(M.count(n)) return M[n];
	return M[n] = max((ll)n, Solve(n/2)+Solve(n/3)+Solve(n/4));
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	ll gg = 0;
	for(int i=1; i<MAX; i++) dp[i] = max(i, dp[i/2] + dp[i/3] + dp[i/4]);
	int n;
	while(scanf("%d", &n) == 1)
		if(n < MAX) printf("%d\n", dp[n]);
		else printf("%lld\n", Solve(n));
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
