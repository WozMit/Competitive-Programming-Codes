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
const int MAX = (int)2e5+5, p = (int)1e9+7;
int f[MAX];

int exp(int a, int b){
	int gg = 1ll;
	while(b){
		if(b&1) gg = (ll)gg*a%p;
		a = (ll)a*a%p;
		b >>= 1;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	f[0] = 1;
	for(int i=1; i<MAX; i++) f[i] = (ll)i*f[i-1]%p;
	int te; scanf("%d", &te);
	for(int t=0; t<te; t++){
		int a, b, n, m; scanf("%d %d %d %d", &a, &b, &n, &m);
		n -= a; m -= b;
		int gg = 0, lim = min(n, m)+1;
		for(int k=0; k<lim; k++)
			gg = (gg + (ll)f[n+m-k]*exp((ll)f[n-k]*f[m-k]%p*f[k]%p, p-2)%p)%p;
		printf("Case %d: %d\n", t+1, gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
