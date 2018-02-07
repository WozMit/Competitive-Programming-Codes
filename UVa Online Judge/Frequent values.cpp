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
const int MAX = (int)1e5+5, oo = 1<<30;
int n, A[MAX];
struct data{
	int gg, maxRight, maxLeft;
	data(){}
	data(int pgg, int pright, int pleft){
		gg = pgg;
		maxRight = pright;
		maxLeft = pleft;
	}
};
data st[4*MAX];

data combine(data a, data b, int i, int j){
	int m = i + (j - i)/2;
	int maxMid = (A[m] == A[m+1] ? (a.maxLeft + b.maxRight):-1);
	data ans = data();
	ans.maxRight = a.maxRight;
	if(maxMid != -1 && A[i] == A[m]) ans.maxRight = maxMid;
	ans.maxLeft = b.maxLeft;
	if(maxMid != -1 && A[m+1] == A[j]) ans.maxLeft = maxMid;
	ans.gg = max(a.gg, max(b.gg, maxMid));
	return ans;
}

void Build(int p = 1, int i = 0, int j = n - 1){
	if(i == j) st[p] = data(1, 1, 1);
	else{
		int m = i + (j - i)/2;
		Build(p<<1, i, m);
		Build(p<<1|1, m+1, j);
		st[p] = combine(st[p<<1], st[p<<1|1], i, j);
	}
}

data Query(int iq, int jq, int p = 1, int i = 0, int j = n - 1){
	if(i > jq || j < iq) return data(-oo, -oo, -oo);
	if(i >= iq && j <= jq) return st[p];
	int m = i + (j - i)/2;
	data l = Query(iq, jq, p<<1, i, m), r = Query(iq, jq, p<<1|1, m+1, j);
	if(l.gg == -oo) return r;
	if(r.gg == -oo) return l;
	return combine(l, r, i, j);
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int q;
	while(scanf("%d", &n) == 1 && n){
		scanf("%d", &q);
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		Build();
		while(q--){
			int a, b; scanf("%d %d", &a, &b);
			a--; b--;
			printf("%d\n", Query(a, b).gg);
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
