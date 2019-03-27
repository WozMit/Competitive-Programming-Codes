//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = (int)5e3 + 5;
const ll oo = (ll)1e15;
int A[MAX];
ll dp[MAX][MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, k, x;
	while(scanf("%d %d %d", &n, &k, &x) == 3){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		dp[0][0] = 0;
		for(int i=1; i<=n; i++)
			for(int j=0; j<=x; j++) dp[i][j] = -oo;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=x; j++)
				for(int h=1; h<=k && i-h>=0; h++)
					dp[i][j] = max(dp[i][j], dp[i-h][j-1] + A[i-1]);
		ll gg = -oo;
		for(int i=n-k+1; i<=n; i++) gg = max(gg, dp[i][x]);
		if(gg < 0) puts("-1");
		else printf("%I64d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
