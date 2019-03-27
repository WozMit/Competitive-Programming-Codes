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
typedef long long int ll;
const int MAX = (int)1e5+5;
int A[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, k;
	while(scanf("%d %d", &n, &k) == 2){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		sort(A, A + n);
		int idx = 0;
		ll sum = 0;
		while(k--){
			while(idx < n && A[idx] - sum <= 0) idx++;
			if(idx >= n) puts("0");
			else{
				A[idx] -= sum;
				printf("%d\n", A[idx]);
				sum += A[idx++];
			}
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
