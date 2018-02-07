//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = (int)1e5+5;
struct vertex{
	int u, v, w;
	vertex(int pu, int pv, int pw){ u = pu; v = pv; w = pw; }
	vertex(int pv, int pw){ v = pv; w = pw; }
	bool operator <(vertex b)const{ return w < b.w; }
};
vector<vertex> E, G[MAX];
int n, p[MAX], range[MAX], total_gg, parent[MAX][25], st[MAX][25], depth[MAX], max_depth;
int e[2*MAX], l[2*MAX], h[MAX], idx, st_lca[2*MAX][15];
map<pair<int, int>, int> M;

int Find(int x){
	if(x == p[x]) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		if(range[fx] > range[fy]) p[fy] = fx;
		else{
			p[fx] = fy;
			if(range[fx] == range[fy]) range[fy]++;
		}
}

void Krushkal(){
	sort(E.begin(), E.end());
	for(int i=0; i<n; i++) p[i] = i, range[i] = 0;
	for(int i=0; i<E.size(); i++){
		int u = E[i].u, v = E[i].v, w = E[i].w;
		if(Find(u) != Find(v)){
			Union(u, v);
			G[u].push_back(vertex(v, w));
			G[v].push_back(vertex(u, w));
			total_gg += w;
		}
	}
}

void dfs(int u, int dep){
	depth[u] = dep;
	max_depth = max(max_depth, dep);
	e[idx] = u;
	l[idx] = dep;
	h[u] = idx++;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i].v, w = G[u][i].w;
		if(v == parent[u][0]) continue;
		parent[v][0] = u;
		st[v][0] = w;
		dfs(v, dep + 1);
		e[idx] = u;
		l[idx++] = dep;
	}
}

int operation(int x, int y){ return l[x] < l[y] ? x:y; }

int kth_parent(int u, int k){
	for(int i=0; k; i++, k >>= 1)
		if(k&1) u = parent[u][i];
	return u;
}

int heaviest_edge(int u, int k){
	if(k > depth[u] || !k) return 0;
	int h = 31 - __builtin_clz(k);
	return max(st[u][h], st[ kth_parent(u, k - (1<<h)) ][h]);
}

void Build(){
	for(int i=0; i<idx; i++) st_lca[i][0] = i;
	for(int j=1; (1<<j)<=idx; j++)
		for(int i=0; i+(1<<j)-1<idx; i++)
			st_lca[i][j] = operation(st_lca[i][j-1], st_lca[i + (1<<(j-1)) ][j - 1]);
	for(int j=1; (1<<j)<=max_depth; j++)
		for(int i=0; i<n; i++)
			if(depth[i] >= (1<<j)){
				parent[i][j] = parent[ parent[i][j-1] ][j-1];
				st[i][j] = max(st[i][j-1], st[ parent[i][j-1] ][j-1]);
			} else st[i][j] = st[i][j-1];
}

int q_lca(int i, int j){
	if(i > j) swap(i, j);
	int k = 31 - __builtin_clz(j - i + 1);
	return operation(st_lca[i][k], st_lca[j - (1<<k) + 1][k]);
}

int lca(int u, int v){ return e[q_lca(h[u], h[v])]; }

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int m;
	while(scanf("%d %d", &n, &m) == 2){
		while(m--){
			int u, v, w; scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			E.push_back(vertex(u, v, w));
			M[make_pair(u, v)] = M[make_pair(v, u)] = w;
		}
		total_gg = 0;
		Krushkal();
		parent[0][0] = max_depth = idx = 0;
		dfs(0, 0);
		Build();
		int m; scanf("%d", &m);
		while(m--){
			int u, v; scanf("%d %d", &u, &v);
			u--; v--;
			int lc = lca(u, v);
			int max_edge = max(heaviest_edge(u, depth[u] - depth[lc]), heaviest_edge(v, depth[v] - depth[lc]));
			printf("%d\n", total_gg - max_edge + M[make_pair(u, v)]);
		}
		E.clear();
		for(int i=0; i<n; i++) G[i].clear();
		M.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
