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
#define fi first
#define se second
const int MAX = (int)1e4+5;
int n, dp[MAX], st[MAX], ed[MAX], p[MAX];
pair<pair<int, int>, int> A[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			int a, b, c; scanf("%d %d %d", &a, &b, &c);
			A[i] = make_pair(make_pair(a, a+b), c);
		}
		sort(A, A+n);
		for(int i=0; i<n; i++) st[i] = A[i].fi.fi, ed[i] = A[i].fi.se, p[i] = A[i].se;
		for(int idx=n-1; idx>=0; idx--){
			int next = lower_bound(st, st+n, ed[idx])-st;
			dp[idx] = max((idx+1 < n ? dp[idx+1]:0), p[idx] + (next < n ? dp[next]:0));
		}
		printf("%d\n", dp[0]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
