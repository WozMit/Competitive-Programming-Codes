//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, A[102], m, x;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		scanf("%d", &m);
		while(m--){
			scanf("%d", &x);
			if(binary_search(A, A+n, x)) printf("%d ", x);
		}
		printf("\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}