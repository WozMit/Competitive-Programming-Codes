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
const int MAX = (int)1e5+5;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t, n, A[MAX];
	scanf("%d", &t);
	for(int k=0; k<t; k++){
		scanf("%d", &n); n--;
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		int max_here = A[0], max_tot = A[0], gg1 = 0, gg2 = 0, f = 0, t = 0;
		for(int i=1; i<n; i++){
			if(max_here < 0) max_here = A[i], f = t = i;
			else max_here += A[i], t = i;
			if(max_here > max_tot) max_tot = max_here, gg1 = f, gg2 = t;
			else if(max_here == max_tot && t-f > gg2-gg1) gg1 = f, gg2 = t;
		}
		if(max_tot < 0) printf("Route %d has no nice parts\n", k+1);
		else printf("The nicest part of route %d is between stops %d and %d\n", k+1, gg1+1, gg2+2);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
