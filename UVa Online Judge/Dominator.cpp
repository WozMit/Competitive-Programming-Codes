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
const int MAX = 105;
vector<int> G[MAX];
bool D[MAX][MAX], V[MAX], reach[MAX];
int deleted;

void dfs(int u, int p){
	V[u] = true;
	if(deleted == -1) D[0][u] = true;
	else reach[u] = true;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(v == deleted || v == p || V[v]) continue;
		dfs(v, u);
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	for(int t=0; t<te; t++){
		int n; scanf("%d", &n);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				int x; scanf("%d", &x);
				if(x) G[i].push_back(j);
			}
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) D[i][j] = false;
		for(int i=0; i<n; i++){
			D[i][i] = true;
			V[i] = D[0][i] = false;
		}
		deleted = -1;
		dfs(0, -1);
		for(int i=0; i<n; i++)
			if(!D[0][i]) D[i][i] = false;
		for(deleted = 1; deleted<n; deleted++){
			for(int i=0; i<n; i++) reach[i] = V[i] = false;
			dfs(0, -1);
			for(int i=1; i<n; i++)
				if(i != deleted) D[deleted][i] = (D[0][i] && !reach[i]);
		}
		printf("Case %d:\n", t+1);
		for(int i=0; i<n; i++){
			printf("+");
			for(int k=0; k<2*n-1; k++) printf("-");
			printf("+\n");
			for(int j=0; j<n-1; j++) printf("|%c", (D[i][j] ? 'Y':'N'));
			printf("|%c|\n", (D[i][n-1] ? 'Y':'N'));
		}
		printf("+");
		for(int k=0; k<2*n-1; k++) printf("-");
		printf("+\n");
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
