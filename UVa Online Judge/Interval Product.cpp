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
int n, q, A[MAX], st[4*MAX];

int combine(int x, int y){
	if(!x || !y) return 0;
	if(x == y) return 1;
	return 2;
}

void Build(int p = 1, int i = 0, int j = n - 1){
	if(i == j) st[p] = (!A[i] ? 0:(A[i]>0 ? 1:2));
	else{
		int m = i + (j - i)/2;
		Build(p<<1, i, m);
		Build(p<<1|1, m+1, j);
		st[p] = combine(st[p<<1], st[p<<1|1]);
	}
}

void Update(int idx, int val, int p = 1, int i = 0, int j = n - 1){
	if(i == j) st[p] = (!val ? 0:(val>0 ? 1:2));
	else{
		int m = i + (j - i)/2;
		if(idx <= m) Update(idx, val, p<<1, i, m);
		else Update(idx, val, p<<1|1, m+1, j);
		st[p] = combine(st[p<<1], st[p<<1|1]);
	}
}

int Query(int iq, int jq, int p = 1, int i = 0, int j = n - 1){
	if(j < iq || i > jq) return -1;
	if(i >= iq && j <= jq) return st[p];
	int m = i + (j - i)/2;
	int l = Query(iq, jq, p<<1, i, m);
	int r = Query(iq, jq, p<<1|1, m+1, j);
	if(l == -1) return r;
	if(r == -1) return l;
	return combine(r, l);
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &q) == 2){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		Build();
		string gg = "";
		while(q--){
			char c; int a, b; scanf(" %c %d %d", &c, &a, &b); a--;
			if(c == 'C') Update(a, b);
			else{
				b--;
				int x = Query(a, b);
				gg += !x ? '0':(x == 1 ? '+':'-');
			}
		}
		printf("%s\n", gg.c_str());
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
