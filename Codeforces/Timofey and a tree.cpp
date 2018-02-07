//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = (int)1e5+5;
vector<int> G[MAX];
int C[MAX], curr_color;
bool flag;

bool dfs(int u, int p){
	flag = flag && (C[u] == curr_color);
	for(int i=0; i<G[u].size(); i++)
		if(G[u][i] != p) dfs(G[u][i], u);
}

bool solve(int u){
	int gg = true;
	for(int i=0; i<G[u].size(); i++){
		curr_color = C[G[u][i]];
		flag = true;
		dfs(G[u][i], u);
		gg = gg && flag;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, u, v;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n-1; i++){
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=0; i<n; i++) scanf("%d", &C[i+1]);
		int a = 0, b = 0;
		for(int i=1; i<=n; i++)
			for(int j=0; j<G[i].size(); j++){
				int v = G[i][j];
				if(C[i] != C[v]) a = i, b = v;
			}
		if(!a) printf("YES\n1\n", 1);
		else if(solve(a)) printf("YES\n%d\n", a);
		else if(solve(b)) printf("YES\n%d\n", b);
		else printf("NO\n");
		for(int i=0; i<=n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
