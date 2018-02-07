//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
ll mod = 1000000007;

ll FExp(ll a, ll b){
	if(b == 0ll) return 1;
	ll gg = FExp(a, b>>1ll)%mod;
	gg = (gg*gg)%mod;
	if(b&1ll) gg = (gg*a)%mod;
	return gg;
}

int main() {
	ll a, n;
	while(scanf("%lld %lld", &a, &n) == 2){
		ll a1 = FExp(a, n+1);
		ll a2 = (((a1*a) % mod)*n) % mod;
		a1 = (a1*(n+1)) % mod;
		ll gg1 = a-a1+a2;
		while(gg1 < 0) gg1 += mod;
		ll gg2 = (a-1)*(a-1);
		cout << gg1/gg2 << endl;
	}
	return 0;
}