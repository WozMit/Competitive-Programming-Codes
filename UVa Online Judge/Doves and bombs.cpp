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
const int MAX = (int)1e4+5;
vector<int> G[MAX];
int dfs_num[MAX], dfs_low[MAX], components[MAX], idx, root, root_child;

void dfs(int u, int p){
	dfs_num[u] = dfs_low[u] = idx++;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(v == p) continue;
		if(dfs_num[v] == -1){
			if(u == root) root_child++;
			dfs(v, u);
			if(dfs_low[v] >= dfs_num[u]) components[u]++;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

bool Cond(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, m;
	while(scanf("%d %d", &n, &m) && n + m){
		int u, v;
		while(scanf("%d %d", &u, &v) && u + v > 0){
			G[u].push_back(v);
			G[v].push_back(u);
		}
		idx = 0;
		for(int i=0; i<n; i++) dfs_num[i] = -1, components[i] = 1;
		for(int i=0; i<n; i++)
			if(dfs_num[i] == -1){
				root = i;
				root_child = 0;
				dfs(i, -1);
				components[i] = root_child;
			}
		pair<int, int> A[n];
		for(int i=0; i<n; i++) A[i] = make_pair(i, components[i]);
		sort(A, A+n, Cond);
		for(int i=0; i<m; i++) printf("%d %d\n", A[i].first, A[i].second);
		printf("\n");
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
