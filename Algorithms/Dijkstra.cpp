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
const int MAX = (int)1e3+5, oo = 1<<30;
struct vertex{
	int v, w;
	vertex(int pv, int pw){ v = pv; w = pw; }
	bool operator < (vertex b)const{ return w > b.w; }
};
int n, d[MAX];
vector<vertex> G[MAX];

void Dijkstra(vertex u){
	for(int i=0; i<n; i++) d[i] = oo;
	d[u.v] = 0;
	priority_queue<vertex> Q;
	Q.push(u);
	while(!Q.empty()){
		u = Q.top(); Q.pop();
		for(int i=0; i<G[u.v].size(); i++){
			int v = G[u.v][i].v, w = G[u.v][i].w;
			if(u.w + w < d[v]){
				d[v] = u.w + w;
				Q.push(vertex(v, d[v]));
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
	int m;
	while(scanf("%d %d", &n, &m) == 2){
		while(m--){
			int u, v, w; scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(vertex(v, w));
		}
		int u; scanf("%d", &u);
		Dijkstra(vertex(u, 0));
		for(int i=0; i<n; i++) printf("d[%d] = %d\n", i, d[i]);
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}

/*
INPUT:

4 4
0 1 6
0 2 11
1 3 9
3 2 2
0
*/