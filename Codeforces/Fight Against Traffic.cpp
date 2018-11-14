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
const int MAX = 1007, oo = 1<<30;
int n, m, s, t, ds[MAX], dt[MAX], G[MAX][MAX];

void bfs(int u, int *d){
	for(int i=0; i<n; i++) d[i] = oo;
	queue<int> Q;
	Q.push(u);
	d[u] = 0;
	while(!Q.empty()){
		u = Q.front(); Q.pop();
		for(int v=0; v<n; v++)
			if(G[u][v]){
				if(d[u] + 1 < d[v]){
					d[v] = d[u] + 1;
					Q.push(v);
				}
			}
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d %d %d", &n, &m, &s, &t) == 4){
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) G[i][j] = 0;
		s--; t--;
		while(m--){
			int v, u; scanf("%d %d", &v, &u);
			v--; u--;
			G[v][u] = G[u][v] = 1;
		}
		bfs(s, ds);
		bfs(t, dt);
		int gg = 0, d = ds[t];
		for(int u=0; u<n; u++)
			for(int v=u+1; v<n; v++)
				if(!G[u][v] && ds[u] + dt[v] + 1 >= d && dt[u] + ds[v] + 1 >= d)
					gg++;
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
