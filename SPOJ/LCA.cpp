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
const int MAX = (int)1e3+5;
vector<int> G[MAX];
int e[2*MAX], l[2*MAX], h[MAX], idx, st[2*MAX][15];

void dfs(int u, int p, int depth){
	e[idx] = u;
	l[idx] = depth;
	h[u] = idx++;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(v == p) continue;
		dfs(v, u, depth + 1);
		e[idx] = u;
		l[idx++] = depth;
	}
}

int operation(int x, int y){ return l[x] < l[y] ? x:y; }

void Build(){
	for(int i=0; i<idx; i++) st[i][0] = i;
	for(int j=1; (1<<j)<=idx; j++)
		for(int i=0; i+(1<<j)-1<idx; i++)
			st[i][j] = operation(st[i][j-1], st[i + (1<<(j-1)) ][j - 1]);
}

int q_lca(int i, int j){
	if(i > j) swap(i, j);
	int k = 31 - __builtin_clz(j - i + 1);
	return operation(st[i][k], st[j - (1<<k) + 1][k]);
}

int lca(int u, int v){ return e[q_lca(h[u], h[v])]; }

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	for(int t=0; t<te; t++){
		int n; scanf("%d", &n);
		//db(n);
		for(int i=0; i<n; i++){
			int m; scanf("%d", &m);
			while(m--){
				int v; scanf("%d", &v); v--;
				G[i].push_back(v);
				G[v].push_back(i);
			}
		}
		idx = 0;
		dfs(0, -1, 0);
		Build();
		printf("Case %d:\n", t + 1);
		int q; scanf("%d", &q);
		while(q--){
			int u, v; scanf("%d %d", &u, &v);
			printf("%d\n", lca(u-1, v-1)+1);
		}
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
