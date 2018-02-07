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
typedef long long int ll;
const int MAX = 10000;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	ll dp[MAX] = {1ll};
	for(int c=1; c<MAX; c++)
		for(int i=c; i<MAX; i++) dp[i] += dp[i-c];
	int n;
	while(scanf("%d", &n) == 1) printf("P(%d) = %lld\n", n, dp[n]);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}

/*
INPUT:
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
50
200
*/