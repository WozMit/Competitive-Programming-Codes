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
typedef long long int ll;
const int MAX = (int)1e5+5;
ll st[4*MAX], lazy[4*MAX];
int n;

void Push_lazy(int p, ll val){
	if(lazy[p] != -1ll) lazy[p] += val;
	else lazy[p] = val;
}

void Refresh(int p, int i, int j){
	if(lazy[p] != -1){
		st[p] += lazy[p]*(j - i + 1);
		if(i != j){
			Push_lazy(p<<1, lazy[p]);
			Push_lazy(p<<1|1, lazy[p]);
		}
		lazy[p] = -1;
	}
}

void Update(int iq, int jq, int val, int p = 1, int i = 0, int j = n-1){
	Refresh(p, i, j);
	if(i >= iq && j <= jq){
		Push_lazy(p, val);
		Refresh(p, i, j);
	} else if(!(j < iq || i > jq)){
		int m = (i + j)/2;
		Update(iq, jq, val, p<<1, i, m);
		Update(iq, jq, val, p<<1|1, m+1, j);
		st[p] = st[p<<1] + st[p<<1|1];
	}
}

ll Query(int iq, int jq, int p = 1, int i = 0, int j = n-1){
	if(j < iq || i > jq) return 0ll;
	Refresh(p, i, j);
	if(i >= iq && j <= jq) return st[p];
	int m = (i + j)/2;
	ll l = Query(iq, jq, p<<1, i, m);
	ll r = Query(iq, jq, p<<1|1, m+1, j);
	return l + r;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		int q; scanf("%d %d", &n, &q);
		for(int i=1; i<4*n; i++) st[i] = 0ll, lazy[i] = -1ll;
		while(q--){
			int c, a, b; scanf("%d %d %d", &c, &a, &b); a--; b--;
			if(!c){
				int v; scanf("%d", &v);
				Update(a, b, v);
			}
			else printf("%lld\n", Query(a, b));
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
