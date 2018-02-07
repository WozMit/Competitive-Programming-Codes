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
int P[25];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t; scanf("%d", &t);
	while(t--){
		int deg, d, k;
		scanf("%d", &deg);
		memset(P, 0, sizeof P);
		for(int i=0; i<=deg; i++) scanf("%d", &P[i]);
		scanf("%d %d", &d, &k);
		ll x = 1ll, prod = 1ll, gg = 0ll;
		while(prod*d < (ll)k) prod = (++x)*(x+1)>>1;
		for(int i=0; i<=deg; i++) gg += P[i]*pow(x, i);
		printf("%lld\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
