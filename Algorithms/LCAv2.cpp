//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
const int MAX = (int) 1e4;
int n, m, depth[MAX], P[MAX][23];
vector<int> G[MAX];

void dfs(int u, int d = 0){
	depth[u] = d;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(depth[v] == -1){
			dfs(v, d+1);
			P[v][0] = u;
		}
	}
}

void Build(){
	depth[n] = -1;
	P[1][0] = -1;
	dfs(1);
	for(int j=1; (1<<j) <= n; j++)
		for(int i=1; i<=n; i++)
			P[i][j] = (P[i][j-1] == -1) ? -1:P[ P[i][j-1] ][j-1];
}

int KthParent(int u, int k){
	for(int i=0; k; i++){
		if(k&1) u = P[u][i];
		k >>= 1;
	}
	return u;
}

int lca(int u, int v){
	if(depth[u] > depth[v]) u = KthParent(u, depth[u]-depth[v]);
	else if(depth[v] > depth[u]) v = KthParent(v, depth[v]-depth[u]);
	if(u == v) return u;
	for(int i=log2(n); i>=0; i--)
		if(P[u][i] != P[v][i]){
			u = P[u][i];
			v = P[v][i];
		}
	return P[u][0];
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &m) == 2){
		int a, b;
		for(int i=1; i<n; i++){
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
			depth[i] = -1;
		}
		Build();
		while(m--){
			scanf("%d %d", &a, &b);
			printf("%d\n", lca(a, b));
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}

/*INPUT:
13 6

1 2
1 3
1 4
3 5
3 6
3 7
6 8
6 9
7 10
7 11
10 12
10 13
8 7
5 11
4 12
12 3
12 11
2 7
*/