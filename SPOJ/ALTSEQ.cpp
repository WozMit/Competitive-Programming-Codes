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
int A[MAX], dp[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		int gg = 1;
		for(int i=0; i<n; i++){
			dp[i] = 1;
			for(int j=0; j<i; j++){
				int ai = A[i], aj = A[j];
				if((ai > 0 && aj < 0 && ai > -aj) || (ai < 0 && aj > 0 && -ai > aj))
					dp[i] = max(dp[i], 1 + dp[j]);
			}
			gg = max(gg, dp[i]);
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
