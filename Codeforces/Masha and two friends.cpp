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

pair<ll, ll> getColors(ll n, ll m, bool cornerWhite = true){
	ll nb = n * m / 2L;
	ll nw = n * m - nb;
	if(cornerWhite) return make_pair(nw, nb);
	return make_pair(nb, nw);
}

bool inter(ll a, ll b, ll c, ll d){
	if(a > c) return inter(c, d, a, b);
	return b >= c;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		ll n, m, x1, x2, x3, x4, y1, y2, y3, y4;
		scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d", &n, &m, &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		pair<ll, ll> p = getColors(n, m);
		ll nw = p.first;
		ll nb = p.second;
		p = getColors(x2 - x1 + 1, y2 - y1 + 1, (x1 + y1)%2 == 0);
		ll w1 = p.first, b1 = p.second;
		p = getColors(x4 - x3 + 1, y4 - y3 + 1, (x3 + y3)%2 == 0);
		ll w2 = p.first, b2 = p.second;
		nw += b1 - w2;
		nb += w2 - b1;
		if(inter(x1,x2,x3,x4) && inter(y1,y2,y3,y4)){
			p = getColors(min(x2,x4) - max(x1,x3) + 1, min(y2,y4) - max(y1,y3) + 1, (max(x1,x3) + max(y1,y3)) % 2 == 0);
			w1 = p.first, b1 = p.second;
			nw -= b1;
			nb += b1;
		}
		printf("%I64d %I64d\n", nw, nb);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
