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
const int MAX = (int)1e6+5;
int euler[2*MAX], lvl[2*MAX], first[MAX], st_lca[2*MAX][25], idx;
vector<int> G[MAX];

void dfs(int u, int p, int depth){
	euler[idx] = u;
	lvl[idx] = depth;
	first[u] = idx++;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(v == p) continue;
		dfs(v, u, depth + 1);
		euler[idx] = u;
		lvl[idx++] = depth;
	}
}

int operation(int x, int y){ return lvl[x] < lvl[y] ? x:y; }

void Build(){
	for(int i=0; i<idx; i++) st_lca[i][0] = i;
	for(int j=1; (1<<j)<=idx; j++)
		for(int i=0; i+(1<<j)-1<idx; i++)
			st_lca[i][j] = operation(st_lca[i][j-1], st_lca[i + (1<<(j-1)) ][j - 1]);
}

int q_lca(int i, int j){
	if(i > j) swap(i, j);
	int k = 31 - __builtin_clz(j - i + 1);
	return operation(st_lca[i][k], st_lca[j - (1<<k) + 1][k]);
}

int lca(int u, int v){ return euler[q_lca(first[u], first[v])]; }

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n-1; i++){
			int u, v; scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		idx = 0;
		dfs(0, -1, 0);
		Build();
		int q; scanf("%d", &q);
		while(q--){
			int u, v; scanf("%d %d", &u, &v);
			printf("%d\n", lca(u, v));
		}
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}

/*
INPUT:

13
0 2
0 9
0 8
9 12
12 7
12 1
8 3
8 11
8 5
11 4
11 10
5 6
6
7 1
4 10
3 10
4 6
6 7
3 5

8
0 1
0 2
0 3
2 4
2 5
5 6
5 7
7
2 4
2 3
2 2
6 7
3 2
3 1
4 5
*/