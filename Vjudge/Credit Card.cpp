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
int A[MAX], max_pref[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, d;
	while(scanf("%d %d", &n, &d) == 2){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		max_pref[n-1] = A[n-1];
		for(int i=n-2; i>=0; i--) max_pref[i] = max(A[i], A[i] + max_pref[i+1]);
		int gg = 0, cur = 0;
		for(int i=0; i<n; i++){
			cur += A[i];
			if(!A[i] && cur < 0){
				int lim = min(d-cur, d - (i == n-1 ? 0:max_pref[i+1]) - cur);
				if(cur + lim < 0){ gg = -1; break; }
				cur += lim;
				gg++;
			}
			if(cur > d){ gg = -1; break; }
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
