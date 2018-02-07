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
int n, bit[MAX], A[MAX];

void Update(int idx, int val){
	for(; idx <= n; idx += idx&(-idx)) bit[idx] += val;
}

int Query(int idx){
	int gg = 0;
	for(; idx > 0; idx -= idx&(-idx)) gg += bit[idx];
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te = 0;
	while(scanf("%d", &n) == 1 && n){
		if(te) printf("\n");
		for(int i=1; i<=n; i++) scanf("%d", &A[i]);
		for(int i=1; i<=n; i++)	bit[i] = 0;
		for(int i=1; i<=n; i++) Update(i, A[i]);
		char s[20], c;
		printf("Case %d:\n", ++te);
		while(scanf(" %[^\n]", &s) && s[0] != 'E'){
			int a, b; sscanf(s, " %c %d %d", &c, &a, &b);
			if(c == 'S'){
				Update(a, b - A[a]);
				A[a] = b;
			} else printf("%d\n", Query(b) - (a ? Query(a-1):0));
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
