//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = (int)2e5+5;
int n, k;
vector<pair<int, int> > A;

bool can(int rep){
	int gg = 0;
	for(auto e : A){
		if(rep > e.first) break;
		gg += e.first / rep;
	}
	return gg >= k;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &k) == 2){
		map<int, int> M;
		for(int i=0; i<n; i++){
			int x; scanf("%d", &x);
			M[x]++;
		}
		vector<pair<int, int> > V(M.begin(), M.end());
		for(int i=0; i<V.size(); i++) swap(V[i].first, V[i].second);
		sort(V.rbegin(), V.rend());
		A = V;
		int l = 1, r = n + 1;
		while(r - l > 1){
			int mid = l + (r - l) / 2;
			if(can(mid)) l = mid;
			else r = mid;
		}
		vector<int> G;
		for(auto e : A){
			for(int i=0; i<e.first/l; i++) G.push_back(e.second);
			if(G.size() >= k) break;
		}
		for(int i=0; i<k; i++) printf("%d ", G[i]);
		printf("\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
