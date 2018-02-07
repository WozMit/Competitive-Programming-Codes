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
#define db(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int d(ll n){
	int gg = 1;
	for(int i=2; i*i<=n; i++){
		int k = 0;
		while(n%(ll)i == 0ll) n /= (ll)i, k++;
		gg *= k+1;
	}
	if(n > 1) gg *= 2;
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ll gg = -1;
		for(int i=1; true; i++){
			ll s = (ll)i*(i+1ll)/2ll;
			int div = d(s);
			if(div > n){
				gg = s;
				break;
			}
		}
		printf("%lld\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
