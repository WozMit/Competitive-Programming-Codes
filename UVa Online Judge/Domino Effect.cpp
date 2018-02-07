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
#include <queue>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = 505, oo = 1<<30;
int n, d[MAX];

struct vertex{
	int v, w;
	vertex(int pv, int pw){ v = pv; w = pw; }
	bool operator < (vertex b) const{ return w > b.w; }
};

vector<vertex> G[MAX];
priority_queue<vertex> Q;

void Dijkstra(vertex u){
	for(int i=0; i<n; i++) d[i] = oo;
	d[u.v] = 0;
	Q.push(u);
	while(!Q.empty()){
		u = Q.top(); Q.pop();
		for(int i=0; i<G[u.v].size(); i++){
			vertex v = G[u.v][i];
			if(u.w + v.w < d[v.v]){
				d[v.v] = u.w + v.w;
				Q.push(vertex(v.v, d[v.v]));
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
	int m, te = 0;
	while(scanf("%d %d", &n, &m) == 2 && (n || m)){
		while(m--){
			int u, v, w; scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			G[u].push_back(vertex(v, w));
			G[v].push_back(vertex(u, w));
		}
		Dijkstra(vertex(0, 0));
		int maxi = 0;
		for(int i=1; i<n; i++) maxi = max(maxi, d[i]);
		pair<double, pair<int, int> > gg = make_pair(0, make_pair(0, -1));
		for(int u=1; u<n; u++)
			for(int i=0; i<G[u].size(); i++){
				vertex v = G[u][i];
				double distance = ((double)d[v.v] + v.w + d[u])/2.0;
				if(distance > gg.first || (distance == gg.first && distance == (double)d[u])){
					if(distance == (double)d[u]) gg = make_pair(distance, make_pair(u, -1));
					else gg = make_pair(distance, make_pair(min(u, v.v), max(u, v.v)));
				}
			}
		printf("System #%d\n", ++te);
		if(gg.second.second == -1) printf("The last domino falls after %.1f seconds, at key domino %d.\n\n", gg.first, gg.second.first + 1);
		else printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n\n", gg.first, gg.second.first + 1, gg.second.second + 1);
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
