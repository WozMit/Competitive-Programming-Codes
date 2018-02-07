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
const int MAX = 5003;
int n, P[MAX][15], D[MAX];
vector<int> T[MAX];

void DFS(int u = 1, int depth = 0){
	D[u] = depth;
	for(int i=0; i<T[u].size(); i++){
		int v = T[u][i];
		if(D[v] == -1){
			DFS(v, depth+1);
			P[v][0] = u;
		}
	}
}

void Build(){
	D[n] = -1;
	for(int i=1; i<=n; i++)
		for(int j=0; 1<<j <=n; j++) P[i][j] = -1;
	DFS();
	for(int j=1; 1<<j <= n; j++)
		for(int i=1; i<=n; i++)
			P[i][j] = P[i][j-1] == -1 ? -1:P[P[i][j-1]][j-1];
}

int KthParent(int u, int k){
	for(int i=0; k; i++){
		if(k&1) u = P[u][i];
		k >>= 1;
	}
	return u;
}

int LCA(int u, int v){
	if(D[u] > D[v]) u = KthParent(u, D[u]-D[v]);
	else if(D[v] > D[u]) v = KthParent(v, D[v]-D[u]);
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
	while(scanf("%d", &n) == 1 && n){
		int a, b, q;
		for(int i=1; i<n; i++){
			scanf("%d %d", &a, &b);
			T[a].push_back(b);
			T[b].push_back(a);
			D[i] = -1;
		}
		Build();
		scanf("%d", &q);
		while(q--){
			scanf("%d %d", &a, &b);
			int lca = LCA(a, b), d = D[a]+D[b]-2*D[lca];
			if(d%2 == 0) printf("The fleas meet at %d.\n", KthParent(D[a]>D[b] ? a:b, d/2));
			else{
				int v1 = KthParent(D[a]>D[b] ? a:b, d/2), v2 = P[v1][0];
				printf("The fleas jump forever between %d and %d.\n", min(v1, v2), max(v1, v2));
			}
		}
		for(int i=0; i<=n; i++) T[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}