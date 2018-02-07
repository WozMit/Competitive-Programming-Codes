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
const int MAX = (int)1e6+5;
int p[MAX], phi[MAX];

void Sieve(){
	for(int i=1; i<MAX; i++) p[i] = i, phi[i] = i;
	for(int i=2; i<MAX; i++)
		if(p[i] == i){
			phi[i]--;
			for(int j=i+i; j<MAX; j+=i){
				phi[j] -= phi[j]/i;
				if(i < p[j]) p[j] = i;
			}
		}
}

int exp(int a, int b, ll mod = 1ll<<63){
	int gg = 1;
	while(b){
		if(b&1) gg = (ll)gg*a%mod;
		a = (ll)a*a%mod;
		b >>= 1;
	}
	return gg;
}

int f(int n, int p, int k){
	int gg = 1, mod = exp(p, k);
	for(int i=2; i<=n; i++)
		if(i%p) gg = (ll)gg*i%mod;
	return gg;
}

int C(ll n, ll m, int p, int k){
	if(m > n) return 0;
	ll r = n - m, cr = r, cm = m;
	int	mod = exp(p, k), e0 = 0, eq = 0, mul = (p == 2 && k >= 3) ? 1:-1, carry = 0, count = 0;
	while(cr > 0ll || cm > 0ll || carry > 0){
		count++;
		int rr = cr%p, rm = cm%p;
		if(rr + rm + carry >= p){
			e0++;
			if(count >= k) eq++;
		}
		carry = (carry + rr + rm)/p;
		cr /= (ll)p, cm /= (ll)p;
	}
	mul = exp(mul, eq)*exp(p, e0);
	int gg = (mul%mod + mod)%mod;
	for(ll temp = 1ll, maxi = n/p; ; temp *= (ll)p){
		gg = (ll)gg * f(n/temp%mod, p, k)%mod * exp(f(m/temp%mod, p, k), phi[mod]-1, mod)%mod * exp(f(r/temp%mod, p, k), phi[mod]-1, mod)%mod;
		if(temp > maxi) break;
	}
	return gg;
}

int C(ll n, ll k, int m){
	int mod = m, gg = 0;
	while(mod > 1){
		int pf = p[mod], power = 0;
		while(mod%pf == 0) mod /= pf, power++;
		int ai = C(n, k, pf, power), ni = exp(pf, power), Ni = m/ni;
		gg = (gg + (ll)ai*Ni%m*exp(Ni, phi[ni]-1, ni)%m)%m;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	int te; scanf("%d", &te);
	while(te--){
		ll n, k; int m; scanf("%lld %lld %d", &n, &k, &m);
		ll np = (n+k-1)/k;
		printf("%lld %d\n", np, C(np + np*k - n - 1, np - 1, m));
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
