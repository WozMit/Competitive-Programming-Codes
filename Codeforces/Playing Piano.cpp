//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = (int)2e5+5;
int A[MAX], B[MAX], dp[MAX][6];

bool play(int i, int fing){
	if(i == 0){
		B[i] = fing;
		return true;
	}
	if(dp[i][fing] != -1) return dp[i][fing];
	bool gg = false;
	for(int d=1; !gg && d<6; d++){
		if(A[i - 1] < A[i] && d < fing){
			B[i] = fing;
			gg = play(i - 1, d);
		}
		else if(A[i - 1] > A[i] && d > fing){
			B[i] = fing;
			gg = play(i - 1, d);
		}
		else if(A[i - 1] == A[i] && d != fing){
			B[i] = fing;
			gg = play(i - 1, d);
		}
	}
	return dp[i][fing] = gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		for(int i=0; i<n; i++) B[i] = -1;
		for(int i=0; i<n; i++)
			for(int j=1; j<6; j++) dp[i][j] = -1;
		bool gg = false;
		for(int d=1; !gg && d<6; d++)
			if(play(n-1, d)){
				gg = true;
				for(int i=0; i<n; i++) printf("%d ", B[i]);
				printf("\n");
			}
		if(!gg) puts("-1");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
