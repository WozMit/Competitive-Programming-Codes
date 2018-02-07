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
int A[MAX], st[MAX][25];

int oper(int x, int y){ return A[x] < A[y] ? x:y; }

void Build(int n){
	for(int i=0; i<n; i++) st[i][0] = i;
	for(int j=1; (1<<j)<=n; j++)
		for(int i=0; i+(1<<j)-1<n; i++)
			st[i][j] = oper(st[i][j-1], st[i + (1<<(j-1)) ][j - 1]);
}

int Query(int i, int j){ //For non-overlapping functions O(log(n))
	int gg = 0;
	for(int k=24; k>=0; k--)
		if((1<<k) <= j - i + 1) gg = oper(gg, st[i][k]), i += 1<<k;
	return gg;
}

int Query(int i, int j){ //For overlapping functions O(1)
	int k = 31 - __builtin_clz(j - i + 1);	//k = (int)log2(j - i + 1)
	return oper(st[i][k], st[j - (1<<k) + 1][k]);
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		Build(n);
		int q; scanf("%d", &q);
		while(q--){
			int a, b; scanf("%d %d", &a, &b);
			printf("%d\n", Query(a, b));
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}

/*
INPUT:

10
2 4 3 1 6 7 8 9 1 7
6
1 2
1 5
3 6
3 5
5 8
0 9
8
3 5 6 8 4 2 7 1
8
1 3
2 5
3 4
1 6
4 4
7 7
0 6
0 7
*/