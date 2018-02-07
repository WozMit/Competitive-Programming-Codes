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
int learn[MAX];
vector<int> G[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	for(int t=0; t<te; t++){
		int n, m; scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++) scanf("%d", &learn[i]);
		while(m--){
			int u, v; scanf("%d %d", &u, &v);
			G[u].push_back(v);
		}
		int gg = 0, last = 0;
		while((int)G[last].size() > 0){
			int maxi = 0, vertex;
			for(int i=0; i<G[last].size(); i++){
				int v = G[last][i];
				if(learn[v] > maxi) maxi = learn[v], vertex = v;
			}
			gg += maxi;
			last = vertex;
		}
		printf("Case %d: %d %d\n", t+1, gg, last);
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
