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
const int MAX = (int)1e3+5;

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, A[MAX];
	while(scanf("%d", &n) == 1){
		scanf("%d", &A[0]);
		int gcd = A[0];
		for(int i=1; i<n; i++){
			int x; scanf("%d", &x);
			gcd = __gcd(gcd, x);
			A[i] = x;
		}
		if(A[0] != gcd) puts("-1");
		else{
			printf("%d\n", n > 1 ? 2*n-2:2);
			for(int i=1; i<n-1; i++) printf("%d %d ", gcd, A[i]);
			printf("%d %d\n", gcd, A[n-1]);
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
