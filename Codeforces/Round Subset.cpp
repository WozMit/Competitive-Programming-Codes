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
const int MAX = 205, oo = 1<<30;
typedef long long int ll;
int dp[MAX][26*MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, k, p2[MAX], p5[MAX];
	while(scanf("%d %d", &n, &k) == 2){
		int max5 = 0;
		for(int i=0; i<n; i++){
			ll x; scanf("%I64d", &x);
			p2[i] = p5[i] = 0;
			while(x%2ll == 0ll) x /= 2ll, p2[i]++;
			while(x%5ll == 0ll) x /= 5ll, p5[i]++;
			max5 += p5[i];
		}
		for(int i=0; i<=k; i++)
			for(int j=0; j<=max5; j++) dp[i][j] = -oo;
		dp[0][0] = 0;
		for(int i=0; i<n; i++){
			for(int j=k-1; j>=0; j--)
				for(int h=0; h<=max5; h++)
					dp[j+1][ h+p5[i] ] = max(dp[j+1][ h+p5[i] ], dp[j][h] + p2[i]);
		}
		int gg = 0;
		for(int i=0; i<=max5; i++) gg = max(gg, min(i, dp[k][i]));
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
