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
const int MAX = 105;
vector<int> G[MAX];
int dfs_num[MAX], dfs_low[MAX], idx, root, root_children;
bool cut_vertex[MAX];

void dfs(int u, int p){
	dfs_num[u] = dfs_low[u] = idx++;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(v == p) continue;
		if(dfs_num[v] == -1){
			if(u == root) root_children++;
			dfs(v, u);
			if(dfs_low[v] >= dfs_num[u]) cut_vertex[u] = true;
			//if(dfs_low[v] > dfs_num[u]) printf("Bridge: (%d-%d)\n", u, v);
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
	while(scanf("%d", &n) == 1 && n){
		//db(n);
		int u, v;
		char s[1000];
		while(scanf("%d", &u) == 1 && u){
			u--;
			scanf(" %[^\n]", &s);
			char *token=strtok(s," ");
			while(token != NULL){
				if(sscanf(token, "%d", &v) > 0){
					v--;
					G[u].push_back(v);
					G[v].push_back(u);
				}
				token = strtok(NULL, " ");
			}
		}
		for(int i=0; i<n; i++) dfs_num[i] = -1, cut_vertex[i] = false;
		idx = 0;
		for(int i=0; i<n; i++)
			if(dfs_num[i] == -1){
				root = i;
				root_children = 0;
				dfs(i, -1);
				cut_vertex[i] = (root_children > 1);
			}
		int gg = 0;
		for(int i=0; i<n; i++)
			if(cut_vertex[i]) gg++;
		printf("%d\n", gg);
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
