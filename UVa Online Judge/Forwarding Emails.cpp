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
const int MAX = (int)5e4+5;
int G[MAX], n[MAX], maxi, gg;
bool V[MAX];

void dfs(int u){
	n[u] = 0;
	int v = G[u];
	V[u] = true;
	if(!V[v]){
		dfs(v);
		n[u] = 1+n[v];
	}
	V[u] = false;
	if(n[u] > maxi) maxi = n[u], gg = u;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int k, m, x, y;
	scanf("%d", &k);
	for(int t=0; t<k; t++){
		scanf("%d", &m);
		for(int i=0; i<m; i++){
			scanf("%d %d", &x, &y);
			G[x] = y;
			n[i+1] = -1;
		}
		maxi = -1;
		for(int i=1; i<=m; i++)
			if(n[i] == -1) dfs(i);
		printf("Case %d: %d\n", t+1, gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
