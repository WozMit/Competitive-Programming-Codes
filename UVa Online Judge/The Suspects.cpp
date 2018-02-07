//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = (int)3e4+5;
vector<int> G[MAX];
bool V[MAX];
int gg;

void dfs(int u, int p){
	gg++;
	V[u] = true;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(v == p || V[v]) continue;
		dfs(v, u);
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, m;
	while(scanf("%d %d", &n, &m) == 2 && n+m){
		while(m--){
			int k; scanf("%d", &k);
			int t[k];
			for(int i=0; i<k; i++) scanf("%d", &t[i]);
			for(int i=0; i<k; i++)
				for(int j=i+1; j<k; j++){
					G[t[i]].push_back(t[j]);
					G[t[j]].push_back(t[i]);
				}
		}
		for(int i=0; i<n; i++) V[i] = false;
		gg = 0;
		dfs(0, -1);
		printf("%d\n", gg);
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
