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
const int MAX1 = 18, MAX2 = 65540;
int n, x[MAX1], y[MAX1];
double G[MAX1][MAX1], dp[MAX2];

double Solve(int m){
	if(m == (1<<(2*n))-1) return 0;
	if(dp[m] != -1) return dp[m];
	double gg = 1<<30;
	for(int i=0; i<2*n; i++)
		if(!(m&(1<<i)))
			for(int j=i+1; j<2*n; j++)
				if(!(m&(1<<j))) gg = min(gg, G[i][j]+Solve(m|(1<<i)|(1<<j)));
	return dp[m] = gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	char s[20];
	int k = 0;
	while(scanf("%d", &n) == 1 && n){
		for(int i=0; i<2*n; i++) scanf("%s %d %d", s, &x[i], &y[i]);
		for(int i=0; i<2*n; i++)
			for(int j=i+1; j<2*n; j++)
				G[i][j] = hypot(x[j]-x[i], y[j]-y[i]);
		for(int i=0; i<MAX2; i++) dp[i] = -1;
		printf("Case %d: %.2f\n", ++k, Solve(0));
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
