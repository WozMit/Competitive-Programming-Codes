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
const int MAX = (int)1e4;
int n, k, dp[MAX], A[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &k) == 2){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		for(int i=1; i<=k; i++) dp[i] = 0;
		dp[0] = 1;
		for(int i=0; i<n; i++)
			for(int j=k; j>=A[i]; j--)
				if(A[i] <= j) dp[j] |= dp[j-A[i]];
		if(dp[k]) printf("Solution found.\n");
		else printf("No solution.\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}

/*
INPUT:
5 12
6 7 3 3 10

5 12
6 7 3 4 10

4 7
1 3 4 5
*/