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
int n, A[MAX], st[4*MAX];

void Build(int p = 1, int i = 0, int j = n-1){
	if(i == j) st[p] = A[i];
	else{
		int m = (i + j)/2;
		Build(p<<1, i, m);
		Build(p<<1|1, m+1, j);
		st[p] = min(st[p<<1], st[p<<1|1]);
	}
}

int Query(int iq, int jq, int p = 1, int i = 0, int j = n-1){
	if(i > jq || j < iq) return oo;
	if(i >= iq && j <= jq) return st[p];
	int m = (i + j)/2;
	int l = Query(iq, jq, p<<1, i, m);
	int r = Query(iq, jq, p<<1|1, m+1, j);
	return min(l, r);
}

void Update(int idx, int val, int p = 1, int i = 0, int j = n-1){
	if(i == j) st[p] = val;
	else{
		int m = (i + j)/2;
		if(idx <= m) Update(idx, val, p<<1, i, m);
		else Update(idx, val, p<<1|1, m+1, j);
		st[p] = min(st[p<<1], st[p<<1|1]);
	}
}

/*
using namespace std;
const int MAX = (int)1e5+5;
int n, st[4*MAX], lazy[4*MAX];

int operation(int x, int y){
	return x + y;
}

void Build(int p = 1, int i = 0, int j = n-1){
	if(i == j) st[p] = 0, lazy[p] = -1;
	else{
		int m = (i + j)/2;
		Build(p<<1, i, m);
		Build(p<<1|1, m+1, j);
		lazy[p] = -1;
		st[p] = operation(st[p<<1], st[p<<1|1]);
	}
}

void Push_lazy(int p, int val){
	if(lazy[p] != -1) lazy[p] += val;
	else lazy[p] = val;
}

void Refresh(int p, int i, int j){
	if(lazy[p] != -1){
		st[p] += lazy[p]*(j - i + 1);
		if(i != j){
			Push_lazy(p<<1, lazy[p]);
			Push_lazy(p<<1|1, lazy[p]);
		}
		lazy[p] = -1;
	}
}

void Update(int iq, int jq, int val, int p = 1, int i = 0, int j = n-1){
	Refresh(p, i, j);
	if(i >= iq && j <= jq){
		Push_lazy(p, val);
		Refresh(p, i, j);
	} else if(!(j < iq || i > jq)){
		int m = (i + j)/2;
		Update(iq, jq, val, p<<1, i, m);
		Update(iq, jq, val, p<<1|1, m+1, j);
		st[p] = operation(st[p<<1], st[p<<1|1]);
	}
}

int Query(int iq, int jq, int p = 1, int i = 0, int j = n-1){
	if(j < iq || i > jq) return 0;
	Refresh(p, i, j);
	if(i >= iq && j <= jq) return st[p];
	int m = (i + j)/2;
	int l = Query(iq, jq, p<<1, i, m);
	int r = Query(iq, jq, p<<1|1, m+1, j);
	return operation(l, r);
}
*/

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		Build();
		int q; scanf("%d", &q);
		while(q--){
			int a, b; scanf("%d %d", &a, &b);
			printf("%d\n", Query(a, b));
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
