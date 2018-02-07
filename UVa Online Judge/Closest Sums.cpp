//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
int A[1005];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, q, x, k = 0;
	while(scanf("%d", &n) == 1 && n){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		scanf("%d", &q);
		printf("Case %d:\n", ++k);
		while(q--){
			scanf("%d", &x);
			int dif = 1<<30, gg = -223223223;
			for(int i=0; i<n; i++)
				for(int j=i+1; j<n; j++)
					if(abs(A[i]+A[j]-x) < dif) dif = abs(A[i]+A[j]-x), gg = A[i]+A[j];
			printf("Closest sum to %d is %d.\n", x, gg);
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
