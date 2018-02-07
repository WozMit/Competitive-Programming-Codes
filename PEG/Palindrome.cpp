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

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		int dp1[n], dp2[n], dp3[n];
		string s; cin >> s;
		memset(dp1, 0, sizeof dp1);
		for(int i=0; i<n; i++) dp2[i] = (s[i] == s[i+1] ? 0:1);
		for(int len=2; len<n; len++){
			for(int i=0, j=i+len; j<n; i++, j++)
				dp3[i] = (s[i] == s[j] ? dp1[i+1]:(1 + min(dp2[i], dp2[i+1])));
			for(int i=0; i<n; i++){
				dp1[i] = dp2[i];
				dp2[i] = dp3[i];
			}
		}
		printf("%d\n", dp3[0]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
