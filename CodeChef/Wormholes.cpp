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
const int MAX = (int)1e5+5;
int V[MAX], W[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, x, y;
	while(scanf("%d %d %d", &n, &x, &y) == 3){
		vector<pair<int, int> > C(n);
		for(int i=0; i<n; i++){
			int a, b; scanf("%d %d", &a, &b);
			C[i] = make_pair(a, b);
		}
		for(int i=0; i<x; i++) scanf("%d", &V[i]);
		for(int i=0; i<y; i++) scanf("%d", &W[i]);
		sort(V, V+x);
		sort(W, W+y);
		int gg = 1<<30;
		for(int i=0; i<n; i++){
			int a = C[i].first, b = C[i].second;
			int pv = lower_bound(V, V+x, a)-V, pw = lower_bound(W, W+y, b)-W;
			if(pv == x || (pv >= 0 && V[pv] > a)) pv--;
			if(pw == y) pw--;
			if(V[pv] <= a && b <= W[pw]) gg = min(gg, W[pw] - V[pv] + 1);
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
