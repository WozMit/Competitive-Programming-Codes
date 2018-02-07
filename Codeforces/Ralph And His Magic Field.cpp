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
const int p = (int)1e9+7;

int exp(ll a, ll b){
	int gg = 1;
	while(b > 0){
		if(b&1ll) gg = (ll)gg*a%p;
		a = a*a%p;
		b >>= 1ll;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	ll n, m; int k;
	while(scanf("%I64d %I64d %d", &n, &m, &k) == 3){
		int gg;
		if(k == -1 && (n+m)&1) gg = 0;
		else gg = exp(exp(2, n-1), m-1);
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
