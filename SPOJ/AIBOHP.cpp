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
const int MAX = 6105;
int dp[MAX][MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		string s; cin >> s;
		int n = s.size();
		for(int i=0; i<n; i++){
			dp[i][i] = 0;
			if(i < n-1) dp[i][i+1] = (s[i] == s[i+1] ? 0:1);
		}
		for(int len=2; len<n; len++)
			for(int i=0, j=i+len; j<n; i++, j++)
				if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
				else dp[i][j] = 1 + min(dp[i][j-1], dp[i+1][j]);
		printf("%d\n", dp[0][n-1]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
