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
	int A[55], n;
	while(scanf("%d", &n) == 1 && n){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		int t = 0, c = 0;
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++){
				t++;
				if(__gcd(A[i], A[j]) == 1) c++;
			}
		if(c) printf("%.6f\n", sqrt(6.0*t/(double)c));
		else printf("No estimate for this data set.\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
