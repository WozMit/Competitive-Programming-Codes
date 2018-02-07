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
int A[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, x, y;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++){
			scanf("%d %d", &x, &y);
			A[i] = min(x, y);
		}
		sort(A, A+n);
		int gg = 1, count = 1, last = 1;
		A[0] = 1;
		for(int i=1; i<n; i++)
			if(A[i] != A[i-1]){
				A[i] = ++last;
				gg = max(gg, ++count);
			}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
