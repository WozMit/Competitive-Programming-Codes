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
const int mod = (int)1e9+9;
int n, m, k;

int exp(int a, int b){
	ll gg = 1ll;
	while(b){
		if(b&1) gg = (ll)gg*a%mod;
		a = (ll)a*a%mod;
		b >>= 1;
	}
	return gg;
}

bool Can(int x){
	int a = m - x*k;
	ll size = (ll)x*k + (ll)a/(k-1)*k + a%(k-1) - (a%(k-1) ? 0:1);
	return size <= (ll)n;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d %d", &n, &m, &k) == 3){
		int i = Can(0) ? -1:0, j = m/k;
		while(j - i > 1){
			int m = i + (j - i)/2;
			if(Can(m)) j = m;
			else i = m;
		}
		int gg = ((ll)(exp(2, j+1) - 2 + mod)*k%mod + ((ll)m - (ll)j*k%mod + (ll)mod)%mod)%mod;
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
