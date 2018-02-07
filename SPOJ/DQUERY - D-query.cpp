//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <map>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
const int MAX = 30005;
int n, BIT[MAX];
map<int, int> O;

void Update(int idx, int v){ for(; idx<=n; idx += idx&(-idx)) BIT[idx] += v; }

int Sum(int idx){
	int gg = 0;
	for(; idx; idx -= idx&(-idx)) gg += BIT[idx];
	return gg;
}

bool cond(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	scanf("%d", &n);
	int x;
	for(int i=0; i<n; i++){
		scanf("%d", &x);
		if(O.count(x) > 0) Update(O[x], -1);
		O[x] = i+1;
		Update(i+1, 1);
	}
	vector<pair<int, int> > V;
	int q, a, b;
	scanf("%d", &q);
	db(q);
	while(q--){
		scanf("%d %d", &a, &b);
		V.push_back(make_pair(a, b));
	}
	sort(V.begin(), V.end(), cond);
	for(int i=0; i<V.size(); i++){
		a = V[i].first, b = V[i].second;
		printf("%d\n", Sum(b)-Sum(a-1));
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}