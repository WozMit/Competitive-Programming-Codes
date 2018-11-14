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
const int MAX = (int)2e5+7;
vector<int> G[MAX];
int da[MAX], db[MAX];

void dfs(int u, int parent, int *d){
	for(int v : G[u]){
		if(v == parent) continue;
		d[v] = d[u] + 1;
		dfs(v, u, d);
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, b;
	while(scanf("%d %d", &n, &b) == 2){
		b--;
		for(int i=0; i<n-1; i++){
			int u, v; scanf("%d %d", &u, &v); u--; v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		da[0] = db[b] = 0;
		dfs(0, 0, da);
		dfs(b, b, db);
		int gg = 0;
		for(int i=0; i<n; i++)
			if(db[i] < da[i])
				gg = max(gg, da[i]);
		printf("%d\n", 2*gg);
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
