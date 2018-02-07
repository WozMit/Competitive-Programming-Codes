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

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te, M[10][10], P[10];
	for(int i=0; i<10; i++) P[i] = i;
	scanf("%d", &te);
	while(te--){
		int n, gg = 1<<30; scanf("%d", &n);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) scanf("%d", &M[i][j]);
		do{
			int sum = 0;
			for(int i=0; i<n; i++) sum += M[i][P[i]];
			gg = min(gg, sum);
		}while(next_permutation(P, P+n));
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
