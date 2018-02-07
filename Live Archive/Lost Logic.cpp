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
const int MAX = 55;
int n, A[MAX], B[MAX], C[MAX];

bool Check(int a, int b, int c){
	if(c == 0) return !((A[a] && !A[b]) || (B[a] && !B[b]) || (C[a] && !C[b]));
	if(c == 1) return !((!A[a] && !A[b]) || (!B[a] && !B[b]) || (!C[a] && !C[b]));
	if(c == 2) return !((A[a] && A[b]) || (B[a] && B[b]) || (C[a] && C[b]));
	return !((!A[a] && A[b]) || (!B[a] && B[b]) || (!C[a] && C[b]));
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		for(int i=0; i<n; i++) scanf("%d", &B[i]);
		for(int i=0; i<n; i++) scanf("%d", &C[i]);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(i != j){
					if(Check(i, j, 0)) printf("x%d -> x%d\n", i+1, j+1);
					if(Check(i, j, 1)) printf("!x%d -> x%d\n", i+1, j+1);
					if(Check(i, j, 2)) printf("x%d -> !x%d\n", i+1, j+1);
					if(Check(i, j, 3)) printf("!x%d -> !x%d\n", i+1, j+1);
				}
		db("juan");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
