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
const int MAX = (int)2e5+5;
const ll oo = 1ll<<62ll;
int n, A[MAX];
ll st[4*MAX], lazy[4*MAX];

void Build(int p = 1, int i = 0, int j = n - 1){
	if(i == j) st[p] = A[i], lazy[p] = 0ll;
	else{
		int m = i + (j - i)/2;
		Build(p<<1, i, m);
		Build(p<<1|1, m+1, j);
		st[p] = min(st[p<<1], st[p<<1|1]);
		lazy[p] = 0ll;
	}
}

void Refresh(int p, int i, int j){
	if(lazy[p] != 0ll){
		st[p] += lazy[p];
		if(i != j){
			lazy[p<<1] += lazy[p];
			lazy[p<<1|1] += lazy[p];
		}
		lazy[p] = 0ll;
	}
}

void Update(int iq, int jq, ll val, int p = 1, int i = 0, int j = n-1){
	Refresh(p, i, j);
	if(i >= iq && j <= jq){
		lazy[p] += val;
		Refresh(p, i, j);
	} else if(!(j < iq || i > jq)){
		int m = i + (j - i)/2;
		Update(iq, jq, val, p<<1, i, m);
		Update(iq, jq, val, p<<1|1, m+1, j);
		st[p] = min(st[p<<1], st[p<<1|1]);
	}
}

ll Query(int iq, int jq, int p = 1, int i = 0, int j = n-1){
	if(j < iq || i > jq) return oo;
	Refresh(p, i, j);
	if(i >= iq && j <= jq) return st[p];
	int m = i + (j - i)/2;
	return min(Query(iq, jq, p<<1, i, m), Query(iq, jq, p<<1|1, m+1, j));
}

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
		char s[25];
		while(q--){
			scanf(" %[^\n]", &s);
			int oper = 0, len = strlen(s);
			for(int i=0; i<len; i++)
				if(s[i] == ' ') oper++;
			if(oper == 1){
				int a, b; sscanf(s, "%d %d", &a, &b);
				if(b < a) printf("%I64d\n", min(Query(0, b), Query(a, n-1)));
				else printf("%I64d\n", Query(a, b));
			} else{
				int a, b, c; sscanf(s, "%d %d %d", &a, &b, &c);
				if(b < a){
					Update(0, b, (ll)c);
					Update(a, n-1, (ll)c);
				}
				else Update(a, b, (ll)c);
			}
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
