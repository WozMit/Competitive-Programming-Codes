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
int n, x, A[MAX];
ll C[MAX];

ll cost(int k){
	for(int i=0; i<n; i++) C[i] = A[i] + (i + 1ll)*(ll)k;
	sort(C, C+n);
	ll gg = 0ll;
	for(int i=0; i<k; i++) gg += C[i];
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &x) == 2){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		int i = 0, j = n + 1;
		while(j - i > 1){
			int m = i + (j - i)/2;
			if(cost(m) <= x) i = m;
			else j = m;
		}
		printf("%d %d\n", i, cost(i));
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
