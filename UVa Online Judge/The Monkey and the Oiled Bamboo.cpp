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
const int MAX = (int)1e5+5;
int n, A[MAX];

bool Can(int k){
	for(int i=0; i<n; i++)
		if(A[i] - (i ? A[i-1]:0) > k) return false;
		else if(A[i] - (i ? A[i-1]:0) == k) k--;
	return true;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	for(int t=0; t<te; t++){
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		int i = 0, j = (int)1e7;
		while(j - i > 1){
			int m = i + (j - i)/2;
			if(Can(m)) j = m;
			else i = m;
		}
		printf("Case %d: %d\n", t+1, j);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
