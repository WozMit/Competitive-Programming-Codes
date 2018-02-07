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
vector<int> T[MAX];
int n, e, TSize[MAX];
int chainNro, chainHead[MAX], chainIdx[MAX], chainPos[MAX], chainSize[MAX];

void dfs(int u, int parent){
	TSize[u] = 1;
	for(int i=0; i<T[u].size(); i++){
		int v = T[u][i];
		if(TSize[v] == -1) dfs(v, u);
		if(v != parent) TSize[u] += TSize[v];
	}
}

void HLD(int u, int parent){
	if(chainHead[chainNro] == -1) chainHead[chainNro] = u;
	chainIdx[u] = chainNro;
	chainPos[u] = chainSize[chainNro];
	chainSize[chainNro]++;
	int idx = -1, maxi = -1;
	for(int i=0; i<T[u].size(); i++){
		int v = T[u][i];
		if(v != parent && TSize[v] > maxi) maxi = TSize[v], idx = i;
	}
	if(idx != -1) HLD(T[u][idx], u);
	for(int i=0; i<T[u].size(); i++){
		int v = T[u][i];
		if(v != parent && i != idx){
			chainNro++;
			HLD(v, u);
		}
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	scanf("%d %d", &n, &e);
	int a, b;
	while(e--){
		scanf("%d %d", &a, &b);
		T[a].push_back(b);
		T[b].push_back(a);
	}
	for(int i=0; i<n; i++) TSize[i] = chainHead[i] = -1;
	dfs(0, -1);
	chainNro = 0;
	HLD(0, -1);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}

/*
INPUT:

7 6

0 1
1 4
1 5
0 2
3 6
0 3
*/