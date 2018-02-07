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
const int MAX = 305, mod = 20011;
bool M[MAX][MAX];
int n, m, d, dp[MAX][MAX][MAX][2];

/*int Solve(int i, int j, int k, int dir){
	if(!i && !j) return 1;
	int gg = 0;
	if(M[i][j]){
		if(k > 0){
			if(dir == 0) gg = (i ? Solve(i-1, j, k-1, 0):0);
			else gg = (j ? Solve(i, j-1, k-1, 1):0);
		}
		if(dir == 0) gg += j ? Solve(i, j-1, d-1, 1):0;
		else gg += i ? Solve(i-1, j, d-1, 0):0;
	}
	return gg;	
}*/

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	scanf("%d %d %d", &n, &m, &d);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) scanf("%d", &M[i][j]);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			for(int k=0; k<d; k++){
				if(!i && !j) dp[i][j][k][0] = dp[i][j][k][1] = 1;
				else if(M[i][j]){
					if(k > 0){
						dp[i][j][k][0] = i ? dp[i-1][j][k-1][0]:0;
						dp[i][j][k][1] = j ? dp[i][j-1][k-1][1]:0;
					}
					dp[i][j][k][0] = (dp[i][j][k][0] + (j ? dp[i][j-1][d-1][1]:0))%mod;
					dp[i][j][k][1] = (dp[i][j][k][1] + (i ? dp[i-1][j][d-1][0]:0))%mod;
				} else dp[i][j][k][0] = dp[i][j][k][1] = 0;
			}
	int gg = dp[n-1][m-1][d-1][0];//Solve(n-1, m-1, d-1, 0);
	printf("%d\n", gg);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
