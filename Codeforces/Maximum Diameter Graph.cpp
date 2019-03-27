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
const int MAX = 505;
int deg[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) deg[i] = 0;
		int sumDeg = 0;
		vector<int> ones, others;
		for(int i=0; i<n; i++){
			scanf("%d", &deg[i]);
			sumDeg += deg[i];
			if(deg[i] > 1) others.push_back(i);
			else ones.push_back(i);
		}
		if(2 * n - 2 <= sumDeg){
			if(ones.size() > 0){
				others.push_back(ones[ones.size() - 1]);
				ones.pop_back();
			}
			if(ones.size() > 0){
				others.insert(others.begin(), ones[0]);
				ones.erase(ones.begin());
			}
			int diam = others.size() - 1;
			set<pair<int, int> > E;
			for(int i=1; i<others.size(); i++){
				int u = others[i - 1], v = others[i];
				deg[u]--; deg[v]--;
				if(u > v) swap(u, v);
				E.insert(make_pair(u, v));
			}
			for(int i=0; ones.size() > 0 && i<others.size(); i++)
				while(deg[ others[i] ] > 0 && ones.size() > 0){
					int u = others[i], v = ones[ones.size() - 1];
					deg[u]--; deg[v]--;
					if(u > v) swap(u, v);
					E.insert(make_pair(u, v));
					ones.pop_back();
				}
			printf("YES %d\n%d\n", diam, E.size());
			for(auto e : E) printf("%d %d\n", e.first + 1, e.second + 1);
		} else puts("NO");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
