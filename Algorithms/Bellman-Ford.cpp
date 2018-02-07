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
const int MAX = (int)1e3+5, oo = 1<<30;
int n, d[MAX];
vector<pair<int, int> > G[MAX];

bool Bellman_ford(int u){
	for(int i=0; i<n; i++) d[i] = oo;
	d[u] = 0;
	for(int i=0; i<n-1; i++)
		for(u = 0; u<n; u++)
			for(int j=0; j<G[u].size(); j++){
				int v = G[u][j].first, w = G[u][j].second;
				d[v] = min(d[v], d[u] + w);
			}
	for(u=0; u<n; u++)
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i].first, w = G[u][i].second;
			if(d[v] > d[u] + w) return false;
		}
	return true;
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
			G[u].push_back(make_pair(v, w));
		}
		int u; scanf("%d", &u);
		if(Bellman_ford(u))
			for(int i=0; i<n; i++) printf("d[%d] = %d\n", i, d[i]);
		else printf("Negative cicles found.\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}

/*
INPUT:

5 9

0 1 7
0 3 2
1 3 2
1 2 1
2 4 5
3 1 3
3 2 8
3 4 5
4 2 4
0

3 3

0 1 500
1 2 5
2 1 -10
0
*/