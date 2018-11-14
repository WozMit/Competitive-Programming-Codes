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
int n, A[MAX];

bool edge(int u, int v){
	return binary_search(G[u].begin(), G[u].end(), v);
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n-1; i++){
			int u, v; scanf("%d %d", &u, &v); u--; v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		for(int i=0; i<n; i++) A[i]--;
		for(int i=0; i<n; i++) sort(G[i].begin(), G[i].end());
		bool flag = A[0] == 0;
		int i = 0, j = 1;
		while(flag && j < n){
			int k = G[ A[i] ].size() - (A[i] ? 1:0);
			while(flag && k--){
				if(binary_search(G[ A[i] ].begin(), G[ A[i] ].end(), A[j]))
					j++;
				else flag = false;
			}
			i++;
		}
		if(flag) puts("Yes");
		else puts("No");
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
