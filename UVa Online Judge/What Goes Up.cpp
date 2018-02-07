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
int A[MAX], P[MAX], L[MAX], I[MAX];

void print(int f){
	if(f >= 0){
		print(P[f]);
		printf("%d\n", A[f]);
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n = 0, x;
	while(scanf("%d", &x) == 1) A[n++] = x;
	int gg = 0, f = 0;
	for(int i=0; i<n; i++){
		int pos = lower_bound(L, L+gg, A[i]) - L;
		L[pos] = A[i];
		I[pos] = i;
		P[i] = (pos > 0 ? I[pos-1]:-1);
		if(pos == gg) gg++, f = i;
	}
	printf("%d\n-\n", gg);
	print(f);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
