//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
int n, M[16][16], dp[16][16];

int Sol(int i, int j){
	if(i == n) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = M[i][j]+max(Sol(i+1, j), Sol(i+1, j+1));
}

int main(){
	std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0; i<n; i++)
			for(int j=0; j<i+1; j++) cin >> M[i][j];
		memset(dp, -1, sizeof dp);
		cout << Sol(0, 0) << "\n";
	}
	#ifdef WozMit
		//printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s";
	#endif
	return 0;
}
