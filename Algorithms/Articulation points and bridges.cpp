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
const int MAX = (int)1e5+5;
vector<int> G[MAX];
int time_in[MAX], min_in[MAX], idx, root, root_children;
bool cut_vertex[MAX];

void dfs(int u, int p){
	time_in[u] = min_in[u] = idx++;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(v == p) continue;
		if(time_in[v] == -1){
			dfs(v, u);
			if(u == root) root_children++;
			if(min_in[v] >= time_in[u]) cut_vertex[u] = true;
			if(min_in[v] > time_in[u]) printf("Bridge: (%d-%d)\n", u, v);
			min_in[u] = min(min_in[u], min_in[v]);
		}
		else min_in[u] = min(min_in[u], time_in[v]);
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, m;
	while(scanf("%d %d", &n, &m) == 2){
		while(m--){
			int u, v; scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=0; i<n; i++) time_in[i] = -1, cut_vertex[i] = false;
		idx = 0;
		for(int i=0; i<n; i++)
			if(time_in[i] == -1){
				root = i;
				root_children = 0;
				dfs(i, -1);
				cut_vertex[i] = (root_children > 1);
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

6 6
0 1
1 2
1 4
4 3
4 5
2 4
*/