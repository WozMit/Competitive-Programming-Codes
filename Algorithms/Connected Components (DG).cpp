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
int v, e, idx;
vector<int> G[MAX_VAL], G0[MAX_VAL], C, S;
vector<vector<int> > GG;
bool V[MAX_VAL];

void DFS(int node, bool f){
	V[node] = true;
	if(f){
		idx++;
		for(int i=0; i<G[node].size(); i++)
			if(!V[G[node][i]]) DFS(G[node][i], true);
		S.push_back(node);
	}
	else{
		C.push_back(node);
		for(int i=0; i<G0[node].size(); i++)
			if(!V[G0[node][i]]) DFS(G0[node][i], false);
	}
}

void Tarjan(){
	memset(V, false, sizeof V);
	idx = 1;
	for(int i=0; i<v; i++)
		if(!V[i]) DFS(i, true);
	for(int i=0; i<v; i++)
		for(int j=0; j<G[i].size(); j++) G0[G[i][j]].push_back(i);
	memset(V, false, sizeof V);
	for(int i=v-1; i>=0; i--)
		if(!V[S[i]]){
			vector<int> C0;
			C = C0;
			DFS(S[i], false);
			GG.push_back(C);
		}
}

int main() {
	while(scanf("%d %d", &v, &e) == 2){
		int a, b;
		while(e--){
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
		}
		Tarjan();
		for(int i=0; i<GG.size(); i++){
			cout << i+1 << ") ";
			for(int j=0; j<GG[i].size(); j++) printf("%d ", GG[i][j]);
			printf("\n");
		}
		printf("\n");
		for(int i=0; i<v; i++){
			G[i].clear();
			G0[i].clear();
		}
		S.clear();
		C.clear();
		GG.clear();
	}
	return 0;
}

/*INPUT:
8 11
0 1
0 5
1 2
2 3
1 5
2 6
6 2
4 0
5 4
5 6
7 6

8 14
0 1
1 2
5 6
6 5
1 5
4 5
4 0
2 3
2 6
3 7
3 2
7 7
6 7
1 4
*/