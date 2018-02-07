//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <stack>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = 105;
vector<int> G[MAX];
bool V[MAX];
int T[MAX], idx;

void dfs(int u){
	V[u] = 1;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(!V[v]) dfs(v);
	}
	T[idx--] = u;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int v, q, x, y;
	while(scanf("%d %d", &v, &q) == 2 && (v || q)){
		while(q--){
			scanf("%d %d", &x, &y);
			G[x].push_back(y);
		}
		idx = v-1;
		for(int i=1; i<=v; i++)
			if(!V[i]) dfs(i);
		for(int i=0; i<v-1; i++) printf("%d ", T[i]);
		printf("%d\n", T[v-1]);
		memset(V, 0, sizeof V);
		for(int i=1; i<=v; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
