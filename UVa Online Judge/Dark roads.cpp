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
const int MAX = (int)2e5+5;
int n, m, gg, p[MAX], ran[MAX];

struct vertex{
	int u, v, w;
	vertex(int pu, int pv, int pw){ u = pu; v = pv; w = pw; }
	bool operator < (vertex b)const{ return w < b.w; }
};

vector<vertex> E;

int Find(int x){
	if(x == p[x]) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		if(ran[fx] > ran[fy]) p[fy] = fx;
		else{
			p[fx] = fy;
			if(ran[fx] == ran[fy]) ran[fy]++;
		}
}

void Kruskal(){
	sort(E.begin(), E.end());
	for(int i=0; i<n; i++) p[i] = i, ran[i] = 0;
	for(int i=0; i<E.size(); i++){
		int u = E[i].u, v = E[i].v, w = E[i].w;
		if(Find(u) != Find(v)){
			Union(u, v);
			gg -= w;
		}
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &m) == 2 && n + m){
		gg = 0;
		while(m--){
			int u, v, w; scanf("%d %d %d", &u, &v, &w);
			E.push_back(vertex(u, v, w));
			gg += w;
		}
		Kruskal();
		printf("%d\n", gg);
		E.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
