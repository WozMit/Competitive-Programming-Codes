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
const int MAX = 205, oo = 1<<30;
vector<int> G[MAX];
int color[MAX], zeros, ones;

bool dfs(int u, int p, int c){
	color[u] = c;
	if(c) ones++;
	else zeros++;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(v == p || color[v] == 1 - c) continue;
		if(color[v] == c || !dfs(v, u, 1 - c)) return false;
	}
	return true;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		int n, m; scanf("%d %d", &n, &m);
		while(m--){
			int u, v; scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=0; i<n; i++) color[i] = -1;
		int gg = 0;
		for(int i=0; i<n; i++)
			if(color[i] == -1){
				zeros = ones = 0;
				if(dfs(i, -1, 0)) gg += min(zeros ? zeros:oo, ones ? ones:oo);
				else{
					gg = 0;
					break;
				}
			}
		if(gg) printf("%d\n", gg);
		else puts("-1");
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
