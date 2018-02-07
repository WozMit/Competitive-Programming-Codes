//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
const int MAX = (int)1e4+3;
int n, BIT[MAX];

void Update(int idx, int v){
	for(; idx<=n; idx += idx&(-idx)) BIT[idx] += v;
}

void Range_Update(int i, int j, int v){
	Update(i, v);
	Update(j+1, -v);
}

int Sum(int idx){
	int gg = 0;
	for(; idx; idx -= idx&(-idx)) gg += BIT[idx];
	return gg;
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t;
	scanf("%d", &t);
	while(t--){
		int q, i, j, v;
		scanf("%d %d", &n, &q);
		for(int i=0; i<=n; i++) BIT[i] = 0;
		while(q--){
			scanf("%d %d %d", &i, &j, &v);
			Range_Update(i+1, j+1, v);
		}
		scanf("%d", &q);
		while(q--){
			scanf("%d", &i);
			printf("%d\n", Sum(i+1));
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}