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
const int MAX = (int)3e5 + 7;
vector<int> G[MAX], Gr[MAX], T;
char s[MAX];
int visit[MAX], dp[MAX][30], gg;
bool acyclic;

void dfs(int u){
	visit[u] = 1;
	for(int v : G[u])
		if(visit[v] == 1) acyclic = false;
		else if(!visit[v]) dfs(v);
	visit[u] = 2;
	T.push_back(u);
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, m;
	while(scanf("%d %d", &n, &m) == 2){
		scanf("%s", &s);
		while(m--){
			int u, v; scanf("%d %d", &u, &v); u--; v--;
			G[u].push_back(v);
			Gr[v].push_back(u);
		}
		for(int i=0; i<n; i++) visit[i] = 0;
		acyclic = true;
		for(int i=0; i<n; i++)
			if(!visit[i]) dfs(i);
		if(acyclic){
			gg = 1;
			for(int i=0; i<n; i++)
				for(int j=0; j<26; j++) dp[i][j] = 0;
			for(int i=n-1; i>=0; i--){
				int u = T[i];
				for(int v : Gr[u])
					for(int j=0; j<26; j++) dp[u][j] = max(dp[u][j], dp[v][j]);
				gg = max(gg, ++dp[u][s[u] - 97]);
			}
			printf("%d\n", gg);
		}
		else puts("-1");
		for(int i=0; i<n; i++) G[i].clear(), Gr[i].clear();
		T.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
