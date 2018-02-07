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
const int MAX = (int)1e6+5;
int A[MAX], dp1[MAX], dp2[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, k;
	while(scanf("%d %d", &n, &k) == 2){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		k--;
		dp1[0] = A[0];
		dp1[1] = A[1] + A[0];
		for(int i=2; i<n; i++) dp1[i] = A[i] + max(dp1[i-1], dp1[i-2]);
		dp2[n-1] = dp1[n-1];
		if(n > 1) dp2[n-2] = max(dp1[n-2], A[n-2] + dp2[n-1]);
		for(int i=n-3; i>k; i--) dp2[i] = max(dp1[i], A[i] + max(dp2[i+1], dp2[i+2]));
		int gg = max(dp1[k] - A[k], max((k < n-1 ? dp2[k+1]:A[0]), (k < n-2 ? dp2[k+2]:A[0])));
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
