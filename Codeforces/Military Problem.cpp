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
const int MAX = (int)2e5+7;
vector<int> G[MAX];
int sub[MAX], A[MAX], fi[MAX], k;

void dfs(int v){
	fi[v] = k;
	A[k++] = v;
	sub[v] = 1;
	for(int i=0; i<G[v].size(); i++){
		int u = G[v][i];
		dfs(u);
		sub[v] += sub[u];
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, q; scanf("%d %d", &n, &q);
	for(int i=0; i<n-1; i++){
		int x; scanf("%d", &x);
		G[x].push_back(i + 2);
	}
	k = 1;
	dfs(1);
	while(q--){
		int u; scanf("%d %d", &u, &k);
		if(k < sub[u] + 1) printf("%d\n", A[fi[u] + k - 1]);
		else puts("-1");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
