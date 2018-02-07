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
const int MAX = (int)7e4;
int A[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, k;
	while(scanf("%d %d", &n, &k) == 2){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		sort(A, A+n);
		int gg = 0;
		for(int i=0; i<n; i++){
			int pos = lower_bound(A, A+n, A[i] + k) - A;
			if(pos < n) gg += n-pos;
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
