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
const int MAX = (int)3e5+5;
vector<int> G[MAX];
int dfs_num[MAX], dfs_low[MAX], idx;
vector<pair<int, int> > V;

void dfs(int u, int p){
	dfs_num[u] = dfs_low[u] = idx++;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(v == p) continue;
		if(dfs_num[v] == -1){
			dfs(v, u);
			if(dfs_low[v] > dfs_num[u]) V.push_back(make_pair(min(u, v), max(u, v)));
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++){
			int u, x; scanf("%d (%d)", &u, &x);
			while(x--){
				int v; scanf("%d", &v);
				G[u].push_back(v);
			}
		}
		for(int i=0; i<n; i++) dfs_num[i] = -1;
		idx = 0;
		for(int i=0; i<n; i++)
			if(dfs_num[i] == -1) dfs(i, -1);
		sort(V.begin(), V.end());
		printf("%d critical links\n", V.size());
		for(int i=0; i<V.size(); i++) printf("%d - %d\n", V[i].first, V[i].second);
		printf("\n");
		for(int i=0; i<n; i++) G[i].clear();
		V.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
