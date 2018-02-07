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
const int MAX1 = 203, MAX2 = 1003;
int G[MAX1][MAX1], R[MAX2], l, n;
//int dp[MAX2][MAX1][MAX1];

int Solve(int w, int p1, int p2, int p3){
	if(w == n) return 0;
	int gg = G[p1][R[w]] + Solve(w+1, R[w], p2, p3);
	gg = min(gg, G[p2][R[w]] + Solve(w+1, p1, R[w], p3));
	gg = min(gg, G[p3][R[w]] + Solve(w+1, p1, p2, R[w]));
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &l, &n);
		for(int i=0; i<l; i++)
			for(int j=0; j<l; j++) scanf("%d", &G[i][j]);
		for(int i=0; i<n; i++) scanf("%d", &R[i]), R[i]--;
		printf("%d\n", Solve(0, 0, 1, 2));
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
