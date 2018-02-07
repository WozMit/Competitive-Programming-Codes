//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
/*const int MAX = (int)1e5;
int p, fact[MAX];

int pow(int a, int b){
	int gg = 1;
	a %= p;
	while(b){
		if(b&1) gg = (gg*a)%p;
		a = ((ll)a*a)%p;
		b >>= 1;
	}
	return gg;
}

vector<int> getRepresentation(int n){
	vector<int> gg;
	while(n > 0){
		gg.push_back(n%p);
		n /= p;
	}
	return gg;
}

int C(int n, int k){
	if(k > n) return 0;
	return (int)((ll)((fact[n]*pow(fact[n-k], p-2))%p)*(ll)pow(fact[k], p-2))%p;
}

int LTheorem(int m, int n){
	vector<int> M = getRepresentation(m), N = getRepresentation(n);
	fact[0] = 1ll;
	for(int i=1; i<p; i++) fact[i] = ((ll)fact[i-1]*(ll)i)%p;
	ll gg = 1ll;
	for(int i=0; i<N.size(); i++) gg = (gg*(ll)C(M[i], N[i]))%p;
	return (int)gg;
}

int C(ll n, ll k){
	int gg = 1;
	while(n){
		gg = gg*Co[n%p][k%p]%p;
		n /= p, k /= p;
	}
	return gg;
}*/

int inv(int a, int mod){
    int n0 = mod, t, q, x0 = 0, x1 = 1;
    while(a > 1){
        q = a/mod;
        t = mod;
        mod = a%mod;
        a = t;
        t = x0;
        x0 = x1-q*x0;
        x1 = t;
    }
    if(x1 < 0) return x1 + n0;
    return x1;
}

int f(int n, int p, int k){
	int gg = 1, mod = pow(p, k);
	for(int i=2; i<=n; i++)
		if(i%p) gg = (ll)gg*i%mod;
	return gg;
}

int C(int n, int m, int p, int k){
	if(m > n) return 0;
	int r = n - m, mod = pow(p, k), e0 = 0, eq = 0, mul = (p == 2 && k >= 3) ? 1:-1;
	int cr = r, cm = m, carry = 0, count = 0;
	while(cr || cm || carry){
		count++;
		int rr = cr%p, rm = cm%p;
		if(rr + rm + carry >= p){
			e0++;
			if(count >= k) eq++;
		}
		carry = (carry + rr + rm)/p;
		cr /= p, cm /= p;
	}
	mul = pow(mul, eq)*pow(p, e0);
	int gg = (mul%mod + mod)%mod;
	for(int temp = 1, maxi = n/p; ; temp *= p){
		gg = (ll)gg * f(n/temp%mod, p, k)%mod * inv(f(m/temp%mod, p, k), mod)%mod
			* inv(f(r/temp%mod, p, k), mod)%mod;
		if(temp > maxi) break;
	}
	return gg;
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int m, n, p, k;
	while(scanf("%d %d %d %d", &m, &n, &p, &k) == 4){
		printf("C(%d,%d) mod %d^%d = %d\n", m, n, p, k, C(m, n, p, k));
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
