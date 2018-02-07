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
const int MAX = 20005;
int n, BIT[MAX], P[MAX];

void Update(int idx){
	for(; idx<=n; idx += idx&(-idx)) BIT[idx] += 1;
}

int Sum(int idx){
	int gg = 0;
	for(; idx; idx -= idx&(-idx)) gg += BIT[idx];
	return gg;
}

int Znum(int x){ return x-Sum(x); }

int Zpos(int x){
	int i = 1, j = n;
	while(i < j-1){
		int m = (i+j)/2;
		if(Znum(m) >= x) j = m;
		else i = m;
	}
	while(P[j]) j--;
	return j;
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<=n; i++) BIT[i] = P[i] = 0;
		int idx = 1, Zq = n;
		for(int i=1; i<=n; i++){
			int u = Zpos(((i+Znum(idx-1))%Zq--)+1);
			P[u] = i;
			Update(u);
			idx = u;
		}
		for(int i=1; i<=n; i++){
			printf("%d", P[i]);
			if(i != n) printf(" ");
			else printf("\n");
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}