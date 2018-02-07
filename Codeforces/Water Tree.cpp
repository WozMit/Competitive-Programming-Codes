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
const int MAX = (int)5e5+5;
vector<int> G[MAX];
int from[MAX], to[MAX], idx, st[4*MAX], lazy[4*MAX], parent[MAX];

void dfs(int u, int p){
	from[u] = idx++;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(v == p) continue;
		parent[v] = u;
		dfs(v, u);
	}
	to[u] = idx - 1;
}

void Refresh(int p, int i, int j){
	if(lazy[p] != -1){
		st[p] = (lazy[p] == 1 ? (j - i + 1):0);
		if(i != j){
			lazy[p<<1] = lazy[p];
			lazy[p<<1|1] = lazy[p];
		}
		lazy[p] = -1;
	}
}

void Update(int p, int i, int j, int iq, int jq, int v){
	Refresh(p, i, j);
	if(i >= iq && j <= jq){
		lazy[p] = v;
		Refresh(p, i, j);
	}
	else if(j >= iq && i <= jq){
		int m = (i + j)/2;
		Update(p<<1, i, m, iq, jq, v);
		Update(p<<1|1, m+1, j, iq, jq, v);
		st[p] = st[p<<1] + st[p<<1|1];
	}
}

int Query(int p, int i, int j, int iq, int jq){
	if(j < iq || i > jq) return 0;
	Refresh(p, i, j);
	if(i >= iq && j <= jq) return st[p];
	int m = (i + j)/2;
	int l = Query(p<<1, i, m, iq, jq), r = Query(p<<1|1, m+1, j, iq, jq);
	return l + r;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=1; i<n; i++){
			int u, v; scanf("%d %d", &u, &v); u--; v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		idx = 0;
		dfs(0, -1);
		for(int i=0; i<4*n; i++) st[i] = 0, lazy[i] = -1;
		int q; scanf("%d", &q);
		while(q--){
			int op, u; scanf("%d %d", &op, &u); u--;
			if(op == 1){
				int x = Query(1, 0, n-1, from[u], to[u]);
				if(u && x != to[u] - from[u] + 1)
					Update(1, 0, n-1, from[parent[u]], from[parent[u]], 0);
				Update(1, 0, n-1, from[u], to[u], 1);
			}
			else if(op == 2) Update(1, 0, n-1, from[u], from[u], 0);
			else{
				if(Query(1, 0, n-1, from[u], to[u]) != to[u] - from[u] + 1) puts("0");
				else puts("1");
			}
		}
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
