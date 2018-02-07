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
const int MAX = 2003;
int dp[MAX][MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te;
	char s[MAX], t[MAX];
	for(int i=0; i<MAX; i++) dp[i][0] = dp[0][i] = i;
	scanf("%d", &te);
	while(te--){
		cin >> s >> t;
		int n = strlen(s), m = strlen(t);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
				else dp[i][j] = 1+min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]));
		printf("%d\n", dp[n][m]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
