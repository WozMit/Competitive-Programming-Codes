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
using namespace std;
typedef long long int ll;
const int MAX = (int)1e5+3, p1 = (int)1e9+7, p2 = (int)5e8+3;
int a, b, n, f[2*MAX];

int exp(int p, int q, int m){
	if(!p) return 0;
	int gg = 1;
	p %= m;
	if(!p && !q) return 1;
	while(q){
		if(q&1) gg = ((ll)gg*p)%m;
		p = ((ll)p*p)%m;
		q >>= 1;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	f[0] = 1;
	for(int i=1; i<2*MAX; i++) f[i] = ((ll)f[i-1]*i)%p2;
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &a, &b, &n);
		int gg = ((ll)f[2*n]*exp((ll)f[n]*f[n]%p2, p2-2, p2))%p2;
		gg = exp(n ? ((p2+1ll)*gg)%(p1-1):1, b, p1-1);
		gg = exp(a, gg, p1);
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
