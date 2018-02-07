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
int c[MAX], mini;
vector<int> G[MAX];
bool V[MAX];

void dfs(int u, int p){
	mini = min(mini, c[u]);
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
	while(scanf("%d %d", &n, &m) == 2){
		for(int i=0; i<n; i++) scanf("%d", &c[i]);
		while(m--){
			int u, v; scanf("%d %d", &u, &v); u--; v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=0; i<n; i++) V[i] = false;
		ll gg = 0ll;
		for(int i=0; i<n; i++)
			if(!V[i]){
				mini = 1<<30;
				dfs(i, -1);
				gg += mini;
			}
		printf("%I64d\n", gg);
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
