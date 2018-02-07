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
const int mod = 2004;
int n, m[12];

int exp(int a, int b, ll mod_o = 1ll<<63){
	int gg = 1;
	while(b){
		if(b&1) gg = (ll)gg*a%mod_o;
		a = (ll)a*a%mod_o;
		b >>= 1;
	}
	return gg;
}

int f(int n, int p, int k){
	int gg = 1, mod_o = exp(p, k);
	for(int i=2; i<=n; i++)
		if(i%p) gg = (ll)gg*i%mod_o;
	return gg;
}

int C(ll n, ll m, int p, int k){
	ll r = n - m, cr = r, cm = m;
	int	mod_o = exp(p, k), e0 = 0, eq = 0, mul = -1, carry = 0, count = 0;
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
	int gg = (mul%mod_o + mod_o)%mod_o, phi = (mod_o == 167 ? 166:2);
	for(ll temp = 1ll, maxi = n/p; ; temp *= (ll)p){
		gg = (ll)gg * f(n/temp%mod_o, p, k)%mod_o * exp(f(m/temp%mod_o, p, k), phi-1, mod_o)%mod_o * exp(f(r/temp%mod_o, p, k), phi-1, mod_o)%mod_o;
		if(temp > maxi) break;
	}
	return gg;
}

int C(ll n, ll m){
	if(m > n || m < 0) return 0;
	int a = C(n, m, 2, 2), b = C(n, m, 3, 1), c = C(n, m, 167, 1);
	return (501*a + 1336*b + 168*c)%mod;
}

int Solve(int c){
	int gg = C(c + n, c);
	for(int mask=1; mask < (1<<n); mask++){
		int sgn = __builtin_popcount(mask)&1 ? -1:1, sum = c;
		for(int i=0; i<n; i++)
			if(mask&(1<<i)) sum -= m[i] + 1;
		gg = (gg + sgn*C(sum + n, sum) + mod)%mod;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int a, b;
	while(scanf("%d %d %d", &n, &a, &b) == 3){
		for(int i=0; i<n; i++) scanf("%d", &m[i]);
		int gg = (Solve(b) - Solve(a - 1) + mod)%mod;
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
