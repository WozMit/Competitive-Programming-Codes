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
const int MAX = (int)1e4+5;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, A[MAX];
	while(scanf("%d", &n) == 1 && n){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		int gg = A[0], max_here = A[0];
		for(int i=1; i<n; i++){
			max_here = max(A[i], A[i]+max_here);
			gg = max(gg, max_here);
		}
		if(gg > 0) printf("The maximum winning streak is %d.\n", gg);
		else printf("Losing streak.\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
