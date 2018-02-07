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
const int oo = 1<<30, MAX = 1e4+5;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t, n, A[MAX], D[MAX];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=n-1; i>=0; i--) scanf("%d", &A[i]), D[i] = oo;
		for(int i=0; i<n; i++) *lower_bound(D, D+n, A[i]) = A[i];
		int gg = lower_bound(D, D+n, oo)-D;
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
