//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <queue>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = (int)205, oo = 1<<30;
int n, m, e, G[MAX][MAX], rG[MAX][MAX], parent[MAX];

bool bfs(int s, int t){
    bool V[n];
    memset(V, 0, sizeof(V));
    queue<int> Q;
    Q.push(s);
    V[s] = true;
    parent[s] = -1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for (int v=0; v<n; v++){
            if (V[v]==false && rG[u][v] > 0){
                Q.push(v);
                parent[v] = u;
                V[v] = true;
            }
        }
    }
    return (V[t] == true);
}

int FF(int s, int t){
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
             rG[u][v] = G[u][v];
    int gg = 0;
    while (bfs(s, t)){
        int path_flow = oo;
        for (int v=t; v!=s; v=parent[v]){
            int u = parent[v];
            path_flow = min(path_flow, rG[u][v]);
        }
        for (int v=t; v != s; v=parent[v]){
            int u = parent[v];
            rG[u][v] -= path_flow;
            rG[v][u] += path_flow;
        }
        gg += path_flow;
    }
    return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &m, &e);
		int a, b;
		for(int i=1; i<=n+1; i++) G[0][i] = 1;
		while(e--){
			scanf("%d %d", &a, &b);
			G[a+1][b+n+2] = 1;
		}
		for(int i=n+2; i<n+m+2; i++) G[i][n+m+2] = 1;
		n = n+m+3;
		printf("%d\n", FF(0, n-1)-1);
		for(int i=0; i<n; i++) for(int j=0; j<n; j++) G[i][j] = 0;
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
