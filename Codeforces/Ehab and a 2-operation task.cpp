//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = 2005;
int A[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=1; i<=n; i++) scanf("%d", &A[i]);
		int maxi = 0;
		for(int i=1; i<=n; i++) maxi = max(maxi, A[i]);
		maxi = (int)1e6 - maxi;
		for(int i=1; i<=n; i++) A[i] += maxi;
		printf("%d\n1 %d %d\n", n+1, n, maxi);
		for(int i=1; i<=n; i++){
			printf("2 %d %d\n", i, (A[i] - i));
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
