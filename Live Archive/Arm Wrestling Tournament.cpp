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
#define fi first
#define se second
using namespace std;
const int MAX = (int)4e4;
int A[MAX], np, k, n;
pair<int, int> B[MAX];
vector<int> gg;

void Process(int idx){
	int len = n;
	while(len > 1){
		for(int i=0, pos = 0; i<len; i+=2, pos++){
			int wfi, wse, lfi, lse;
			if(B[i+1].fi > B[i].fi)
				wfi = B[i+1].fi, wse = B[i+1].se, lfi = B[i].fi, lse = B[i].se;
			else
				wfi = B[i].fi, wse = B[i].se, lfi = B[i+1].fi, lse = B[i+1].se;
			B[pos] = make_pair(min(A[wse], wfi - lfi + k), wse);
			if(idx == wse) gg.push_back(lse);
		}
		len /= 2;
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		scanf("%d %d", &np, &k);
		n = 1<<np;
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		for(int i=0; i<n; i++) B[i] = make_pair(A[i], i);
		Process(-1);
		int winner = B[0].se;
		for(int i=0; i<n; i++) B[i] = make_pair(A[i], i);
		Process(winner);
		printf("%d\n", B[0].se+1);
		for(int i=0; i<np-1; i++) printf("%d ", gg[i]+1);
		printf("%d\n", gg[np-1]+1);
		gg.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
