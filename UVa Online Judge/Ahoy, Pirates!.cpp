//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <bitset>
#define db(x) cout << #x << " = " << x << "\n"
using namespace std;
bitset<1024003> A;
int n, st[3072009], lazy[3072009];

void Build(int p = 1, int i = 0, int j = n-1){
	if(i == j) st[p] = A[i], lazy[p] = 0;
	else{
		int m = (i+j)/2;
		Build(2*p, i, m);
		Build(2*p+1, m+1, j);
		st[p] = st[2*p]+st[2*p+1];
		lazy[p] = 0;
	}
}

void Push_lazy(int p, int v){
	int k = lazy[p];
	if(!k) lazy[p] = v;
	else{
		if(v < 3) lazy[p] = v;
		else{
			if(k == 1) lazy[p] = 2;
			else if(k == 2) lazy[p] = 1;
			else lazy[p] = 0;
		}
	}
}

void Refresh(int p, int i, int j){
	if(lazy[p]){
		int v = lazy[p];
		if(v == 1) st[p] = j-i+1;
		else if(v == 2) st[p] = 0;
		else st[p] = j-i+1-st[p];
		if(i != j){
			Push_lazy(2*p, v);
			Push_lazy(2*p+1, v);
		}
		lazy[p] = 0;
	}
}

void Update(int iq, int jq, int v, int p = 1, int i = 0, int j = n-1){
	Refresh(p, i, j);
	if(i >= iq && j <= jq){
		Push_lazy(p, v);
		Refresh(p, i, j);
	}else if(j >= iq && i<= jq){
		int m = (i+j)/2;
		Update(iq, jq, v, 2*p, i, m);
		Update(iq, jq, v, 2*p+1, m+1, j);
		st[p] = st[2*p]+st[2*p+1];
	}
}

int Query(int iq, int jq, int p = 1, int i = 0, int j = n-1){
	if(j < iq || i > jq) return 0;
	Refresh(p, i, j);
	if(i >= iq && j <= jq) return st[p];
	int m = (i+j)/2;
	int r = Query(iq, jq, 2*p, i, m);
	int l = Query(iq, jq, 2*p+1, m+1, j);
	return r+l;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int tc, m, t, pos;
	char s[51];
	scanf("%d", &tc);
	for(int th = 0; th<tc; th++){
		scanf("%d", &m);
		pos = n = 0;
		while(m--){
			scanf("%d", &t);
			scanf("%s", &s);
			while(t--)
				for(int i=0; i<strlen(s); i++) A[pos++] = s[i]-48, n++;
		}
		Build();
		char c;
		int a, b, k = 1;
		scanf("%d", &m);
		printf("Case %d:\n", th+1);
		for(int q=0; q<m; q++){
			scanf(" %c %d %d", &c, &a, &b);
			if(c == 'S') printf("Q%d: %d\n", k++, Query(a, b));
			else if(c == 'F') Update(a, b, 1);
			else if(c == 'E') Update(a, b, 2);
			else Update(a, b, 3);
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
