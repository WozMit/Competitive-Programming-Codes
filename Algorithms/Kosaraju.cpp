//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = (int)1e5;
vector<int> G[MAX], rG[MAX], C[MAX];
bool V[MAX];
int n, e, k, P[MAX];

void dfs(int u, bool c){
	V[u] = true;
	if(c){
		C[k].push_back(u);
		for(int i=0; i<rG[u].size(); i++){
			int v = rG[u][i];
			if(!V[v]) dfs(v, 1);
		}
	}else{
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i];
			if(!V[v]) dfs(v, c);
		}
		P[k++] = u;
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &e) == 2){
		int a, b;
		while(e--){
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
		}
		for(int i=0; i<n; i++) V[i] = false;
		k = 0;
		for(int i=0; i<n; i++)
			if(!V[i]) dfs(i, 0);
		for(int i=0; i<n; i++){
			for(int j=0; j<G[i].size(); j++) rG[G[i][j]].push_back(i);
			V[i] = false;
		}
		k = 0;
		for(int i=n-1; i>=0; i--)
			if(!V[P[i]]) dfs(P[i], 1), k++;
		for(int i=0; i<k; i++){
			for(int j=0; j<C[i].size(); j++) cout << C[i][j] << ", ";
			cout << endl;
		}
		for(int i=0; i<n; i++) G[i].clear(), rG[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}

/*
INPUT:

8 14
0 1
1 2
1 3
1 5
2 0
2 3
3 4
4 3
5 4
5 6
6 5
6 7
7 6
7 4
*/