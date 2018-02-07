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
const int MAX = 10;
int M[MAX][MAX*MAX];
set<int> G[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) scanf("%d", &M[i][j]);
		bool flag = true;
		for(int j=0; j<m && flag; j++){
			int u = -1, v = -1, tot = 0;
			for(int i=0; i<n && flag; i++){
				tot += M[i][j];
				if(M[i][j]){
					if(u == -1) u = i;
					else if(v == -1){
						v = i;
						if(G[u].count(v) > 0) flag = false;
						G[u].insert(v);
						if(G[v].count(u) > 0) flag = false;
						G[v].insert(u);
					}
					else flag = false;
				}
			}
			if(tot != 2) flag = false;
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
