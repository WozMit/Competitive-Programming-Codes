//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
map<int, vector<int> > G;
set<int> S;

int BFS(int node, int ttl){
	queue<int> Q;
	Q.push(node);
	map<int, int> D;
	D[node] = 0;
	set<int> R;
	while(!Q.empty()){
		int p = Q.front();
		Q.pop();
		R.insert(p);
		for(int i=0; i<G[p].size(); i++)
			if(!D.count(G[p][i]) || D[p]+1 < D[G[p][i]]){
				D[G[p][i]] = D[p]+1;
				if(D[p] < ttl) Q.push(G[p][i]);
			}
	}
	return R.size();
}

int main() {
	int n, x, y, casE = 0;
	while(scanf("%d", &n) == 1 && n){
		while(n--){
			scanf("%d%d", &x, &y);
			G[x].push_back(y);
			G[y].push_back(x);
			S.insert(x);
			S.insert(y);
		}
		n = S.size();
		while(1){
			scanf("%d%d", &x, &y);
			if(!x && !y) break;
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++casE, n-BFS(x, y), x, y);
		}
		G.clear();
		S.clear();
	}
	return 0;
}