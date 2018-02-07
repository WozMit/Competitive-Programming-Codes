//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <set>
#define db(x) cout << #x << " = " << x << "\n";
#define fi first
#define se second
using namespace std;
const int MAX = (int)1e5+5;
vector<int> G[MAX];
int v, a, b, deg[MAX];
bool U[MAX];
set<pair<int, int> > S;

bool Delete(bool from){
	if(!v) return false;
	bool gg = false;
	set<pair<int, int> >::iterator i = from ? S.end():S.begin();
	if(from) i--;
	while(v && ((i->fi) < a || (i->fi) > v - b - 1)){
		gg = true;
		int u = i->se;
		for(int j=0; j<G[u].size(); j++)
			if(U[G[u][j]]){
				int nei = G[u][j];
				S.erase(make_pair(deg[nei], nei));
				S.insert(make_pair(--deg[nei], nei));
			}
		U[u] = false;
		S.erase(i);
		v--;
		i = from ? S.end():S.begin();
		if(from) i--;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, m;
	while(scanf("%d %d %d %d", &n, &m, &a, &b) == 4){
		v = n;
		while(m--){
			int x, y; scanf("%d %d", &x, &y);
			x--;
			y--;
			G[x].push_back(y);
			G[y].push_back(x);
			deg[x]++;
			deg[y]++;
		}
		for(int i=0; i<n; i++){
			S.insert(make_pair(deg[i], i));
			U[i] = true;
		}
		bool f1 = true, f2 = true;
		while(f1 || f2){
			f1 = Delete(0);
			f2 = Delete(1);
		}
		printf("%d\n", v);
		for(int i=0; i<n; i++) G[i].clear(), deg[i] = 0;
		S.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
