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
const int MAX = 5005;
bool dp[MAX][MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	string s;
	int n;
	while(scanf("%d", &n) == 1){
		cin >> s;
		int gg = 1, ix = 0;
		for(int i=0; i<n; i++){
			dp[i][i] = true;
			if(i < n-1) dp[i][i+1] = false;
			if(i < n-1 && s[i] == s[i+1]){
				dp[i][i+1] = true;
				if(gg == 1) gg++, ix = i;
			}
		}
		for(int len=2; len<n; len++)
			for(int i=0, j=i+len; j<n; i++, j++){
				if(s[i] == s[j] && dp[i+1][j-1]){
					dp[i][j] = true;
					if(j-i+1 > gg) gg = j-i+1, ix = i;
				}
				else dp[i][j] = false;
			}
		printf("%d\n%s\n", gg, s.substr(ix, gg).c_str());
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
