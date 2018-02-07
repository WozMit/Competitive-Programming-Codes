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
const int MAX = (int)105, oo = 1<<30;
int n, e, G[MAX][MAX], rG[MAX][MAX], parent[MAX];

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
	while(scanf("%d %d", &n, &e) == 2){
		int a, b, w, s, t;
		while(e--){
			scanf("%d %d %d", &a, &b, &w);
			G[a][b] = w;
		}
		scanf("%d %d", &s, &t);
		printf("The maximum possible flow is %d\n", FF(s, t));
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) G[i][j] = 0;
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}

/*
INPUT:
6 9

0 1 10
0 2 10
1 2 2
1 3 4
1 4 8
2 4 9
3 5 10
4 3 6
4 5 10
0 5

6 10

0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
0 5

6 7
0 1 1
0 2 1
1 3 1
1 4 1
2 3 1
3 5 1
4 5 1
0 5
*/