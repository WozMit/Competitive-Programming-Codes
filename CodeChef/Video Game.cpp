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
	int n, h; scanf("%d %d", &n, &h);
	int A[n], x, j = 0, p = 0;
	for(int i=0; i<n; i++) scanf("%d", &A[i]);
	while(scanf("%d", &x) == 1){
		if(!x) break;
		else if(x == 1 && j) j--;
		else if(x == 2 && j < n-1) j++;
		else if(x == 3 && !p && A[j]) p = 1, A[j]--;
		else if(x == 4 && p && A[j] < h) p = 0, A[j]++;
	}
	for(int i=0; i<n; i++){
		printf("%d", A[i]);
		if(i < n-1) printf(" ");
		else printf("\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
