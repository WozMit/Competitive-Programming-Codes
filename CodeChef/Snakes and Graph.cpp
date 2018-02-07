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
const int MAX = (int)1e5+5;
vector<int> G[MAX];
int deg[MAX], gg[MAX], p[MAX], rank[MAX], cG;

int Find(int x){
	if(x == p[x]) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy){
		if(rank[fx] > rank[fy]) p[fy] = fx;
		else{
			p[fx] = fy;
			if(rank[fx] == rank[fy]) rank[fy]++;
		}
		cG--;
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		int n, m; scanf("%d %d", &n, &m);
		cG = n;
		for(int i=0; i<n; i++) deg[i] = rank[i] = 0, p[i] = i;
		int a, b;
		while(m--){
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
			deg[a-1]++;
			deg[b-1]++;
		}
		for(int i=n; i>0; i--){
			gg[i-1] = cG - 1;
		}
		for(int i=0; i<n-1; i++) printf("%d ", gg[i]);
		printf("%d\n", gg[n-1]);
		for(int i=0; i<n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
