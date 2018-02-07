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
const int MAX = 155, MAX2 = (int)9e4+5, oo = 1<<30;
int n, A[MAX][2], dp[MAX][MAX2];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d", &n) == 1){
		int sum = 0;
		for(int i=0; i<n; i++){
			scanf("%d %d", &A[i][0], &A[i][1]);
			sum += A[i][0] + A[i][1];
		}
		int lim = sum/2;
		for(int i=0; i<n; i++)
			for(int capacity = 0; capacity <= lim; capacity++){
				int a = A[i][0] + (i ? dp[i-1][capacity-A[i][0]]:0), b = A[i][1] + (i ? dp[i-1][capacity-A[i][1]]:0);
				dp[i][capacity] = max(A[i][0] <= capacity ? a:-oo, A[i][1] <= capacity ? b:-oo);
			}
		int gg = sum - 2*dp[n-1][lim];
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
