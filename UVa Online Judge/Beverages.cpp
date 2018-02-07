//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = 105;
map<string, int> M;
string A[MAX];
vector<int> G[MAX], gg;
int n, in_deg[MAX];

void Kahn(){
	priority_queue<int> Q;
	for(int i=0; i<n; i++)
		if(!in_deg[i]) Q.push(-i);
	while(!Q.empty()){
		int u = -Q.top(); Q.pop();
		gg.push_back(u);
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i];
			in_deg[v]--;
			if(!in_deg[v]) Q.push(-v);
		}
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te = 0;
	char s[55], t[55];
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++){
			scanf("%s", &s);
			M[string(s)] = i;
			A[i] = string(s);
			in_deg[i] = 0;
		}
		int m; scanf("%d", &m);
		while(m--){
			scanf("%s %s", &s, &t);
			int u = M[string(s)], v = M[string(t)];
			G[u].push_back(v);
			in_deg[v]++;
		}
		Kahn();
		printf("Case #%d: Dilbert should drink beverages in this order:", ++te);
		for(int i=0; i<n; i++) printf(" %s", A[gg[i]].c_str());
		printf(".\n\n");
		M.clear();
		for(int i=0; i<n; i++) G[i].clear();
		gg.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
