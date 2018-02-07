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
const int MAX = (int)1e4+5, oo = 1<<30;
vector<int> G[MAX];
int d[MAX];

void dfs(int u, int p){
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(d[u] + 1 < d[v] && v != p){
			d[v] = d[u] + 1;
			dfs(v, u);
		}
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, from; scanf("%d", &n);
	for(int i=0; i<n-1; i++){
		int u, v; scanf("%d %d", &u, &v);
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
		from = u;
	}
	for(int i=0; i<n; i++) d[i] = oo;
	d[from] = 0;
	dfs(from, -1);
	int gg = 0;
	for(int i=0; i<n; i++)
		if(d[i] > gg){
			gg = d[i];
			from = i;
		}
	for(int i=0; i<n; i++) d[i] = oo;
	d[from] = 0;
	dfs(from, -1);
	gg = 0;
	for(int i=0; i<n; i++)
		if(d[i] > gg) gg = d[i];
	printf("%d\n", gg);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
