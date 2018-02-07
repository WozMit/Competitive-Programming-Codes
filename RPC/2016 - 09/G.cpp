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
const int MAX = (int)102;
int dp[MAX][MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t;
	scanf("%d", &t);
	for(int te = 0; te<t; te++){
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){
				if((!i && !j) || (i == n-1 && j == m-1)) scanf(" %c", &dp[i][j]), dp[i][j] = 0;
				else scanf("%d", &dp[i][j]);
				dp[i][j] += max(j ? dp[i][j-1]:0, i ? dp[i-1][j]:0);
			}
		printf("Game Board #%d: %d\n", te+1, dp[n-1][m-1]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
