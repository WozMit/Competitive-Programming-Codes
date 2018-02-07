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
typedef long long int ll;
const int MAX = (int)1e5+5;
vector<pair<int, int> > G[MAX];
int a[MAX], sub[MAX], gg;
ll d[MAX], mini[MAX];

void dfs(int u, int p, bool cut){
	sub[u] = 1;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i].first, w = G[u][i].second;
		if(v == p) continue;
		d[v] = d[u] + w;
		mini[v] = min(mini[u], d[v]);
		if(cut && d[v] - mini[u] > a[v]){
			dfs(v, u, false);
			gg += sub[v];
		}
		else dfs(v, u, cut);
		sub[u] += sub[v];
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
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		for(int u=2; u<n+1; u++){
			int v, w; scanf("%d %d", &v, &w);
			G[u].push_back(make_pair(v, w));
			G[v].push_back(make_pair(u, w));
		}
		for(int i=1; i<=n; i++) d[i] = sub[i] = 0;
		gg = 0;
		mini[1] = 0;
		dfs(1, -1, true);
		printf("%d\n", gg);
		for(int i=1; i<=n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
