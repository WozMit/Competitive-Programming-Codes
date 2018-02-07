//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
const int MAX_VAL = 1000;
int v, e;
vector<int> G[MAX_VAL], C;
bool V[MAX_VAL];

void DFS(int node){
	V[node] = true;
	C.push_back(node);
	for(int i=0; i<G[node].size(); i++)
		if(!V[G[node][i]]) DFS(G[node][i]);
}

int main() {
	while(scanf("%d %d", &v, &e) == 2){
		int a, b;
		while(e--){
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		memset(V, false, sizeof V);
		vector<vector<int> > GG;
		for(int i=0; i<v; i++)
			if(!V[i]){
				vector<int> C0;
				C = C0;
				DFS(i);
				GG.push_back(C);
			}
		for(int i=0; i<GG.size(); i++){
			cout << i+1 << ") ";
			for(int j=0; j<GG[i].size(); j++) cout << GG[i][j] << " ";
			cout << endl;
		}
		for(int i=0; i<v; i++) G[i].clear();
		C.clear();
	}
	return 0;
}

/*INPUT:
7 5

0 2
1 4
2 4
0 4
3 5
*/