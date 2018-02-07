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
const int MAX = (int)1e6+5;
struct vertex{
	int u, v, w;
	vertex(int pu, int pv, int pw){ u = pu; v = pv; w = pw; }
	bool operator < (vertex b)const{ return w < b.w; }
};
int n, m, p[MAX], rank[MAX];
vector<vertex> E;

int Find(int x){
	if(x == p[x]) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		if(rank[fx] > rank[fy]) p[fy] = fx;
		else{
			p[fx] = fy;
			if(rank[fx] == rank[fy]) rank[fy]++;
		}
}

void Kruskal(){
	sort(E.begin(), E.end());
	for(int i=0; i<n; i++) p[i] = i, rank[i] = 0;
	for(int i=0; i<E.size(); i++){
		int u = E[i].u, v = E[i].v, w = E[i].w;
		if(Find(u) != Find(v)){
			Union(u, v);
			printf("%d %d %d\n", u, v, w);
		}
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &m) == 2){
		while(m--){
			int u, v, w; scanf("%d %d %d", &u, &v, &w);
			E.push_back(vertex(u, v, w));
		}
		Kruskal();
		E.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
