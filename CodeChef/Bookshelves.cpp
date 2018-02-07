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
const int MAX = (int)2e5+5;
int n, k, A[MAX];

int deleteThis(int *P, int *Q){
	int swaps = 0, maxp = P[n-1], maxq = Q[n-1];
	for(int i=n-1, j = 0; swaps < k &&  j < n && P[i] > Q[j]; i--, j++)
		if(P[i] > Q[j]){
			maxp = max(P[i-1], Q[j]);
			maxq = max(maxq, P[i]);
			swaps++;
		}
	return maxq + maxp;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &k) == 2){
		for(int i=0; i<2*n; i++) scanf("%d", &A[i]);
		sort(A, A+n);
		sort(A+n, A+2*n);
		printf("%d\n", min(deleteThis(A, &A[n]), deleteThis(&A[n], A)));
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
