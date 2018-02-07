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
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = 2097160;
int p[MAX], primes[155611], pos;
ll gg[65];

void Sieve(){
	for(int i=1; i<MAX; i++) p[i] = (i&1 ? i:2);
	for(int i=3; i*i<MAX; i+=2)
		if(p[i] == i) for(int j=i*i; j<MAX; j+=2*i) p[j] = i;
	primes[0] = 2;
	for(int i=3, j=1; i<MAX; i+=2)
		if(p[i] == i) primes[j++] = i;
}

ll mul(ll a, ll b, ll m){
	ll gg = 0ll;
	while(b){
		if(b&1) gg = (gg + a)%m;
		a = (a + a)%m;
		b >>= 1ll;
	}
	return gg;
}

ll exp(ll a, ll b, ll m){
	ll gg = 1ll;
	while(b){
		if(b&1ll) gg = mul(gg, a, m);
		a = mul(a, a, m);
		b >>= 1ll;
	}
	return gg;
}

bool Miller_Rabin(ll n){
	if((n&1) == 0) return false;
	//int A[] = {2, 7, 61}, r = 0; //values of a to be tested <- recommended for n < 2^32
	int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}, r = 0; //12 recommended val for n < 2^64
	ll d = n-1;
	while((d&1) == 0) r++, d >>= 1;
	for(int i=0; i<12 && A[i] < n-1; i++){
		bool prob_prime = false;
		ll rem = exp(A[i], d, n);
		if(rem == 1ll || rem == n-1ll) prob_prime = true;
		for(int j=1; !prob_prime && j<r; j++){
			rem = mul(rem, rem, n);
			if(rem == 1ll) return false;
			if(rem == n-1) prob_prime = true;
		}
		if(!prob_prime) return false;
	}
	return true;
}

ll Pollards_Rho(ll n){
	/*ll a = (3156151335ll%(n-1))+1, b = (35641561ll%(n-1))+1;
	ll x = 2ll, y = 2ll, d;
	do{
		x = (x*(x+a)+b)%n;
		y = (y*(y+a)+b)%n;
		y = (y*(y+a)+b)%n;
		d = __gcd(abs(x-y), n);
	}while(d == 1ll);
	return d;*/
	ll c = 2;
	ll x = 2, y = 2, i = 1, k = 2, d;
	while(1){
		x = mul(x, x, n) + c;
		if(x >= n) x -= n;
		d = __gcd(x-y, n);
		if(d > 1) return d;
		if(++i == k) y = x, k <<= 1ll;	
	}
	return n;
}

void Factor(int n){
	while(n > 1){
		int pf = p[n];
		while(n%pf == 0){
			n /= pf;
			gg[pos++] = pf;
		}
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	int te; scanf("%d", &te);
	while(te--){
		ll n; scanf("%lld", &n);
		pos = 0;
		//db(n);
		if(n < MAX) Factor(n);
		else{
			int j = 1;
			ll pf = primes[0];
			while(j < 155611 && pf*pf < n){
				while(n%pf == 0){
					n /= pf;
					gg[pos++] = pf;
				}
				pf = primes[j++];
			}
			if(n > 1ll && Miller_Rabin(n)) gg[pos++] = n;
			else if(n > 1ll){
				ll x = sqrtl(n);
				if(x*x == n) gg[pos++] = x, gg[pos++] = x;
				else{
					ll pf1 = Pollards_Rho(n);
					ll pf2 = n/pf1;
					if(pf1 < pf2) gg[pos++] = pf1, gg[pos++] = pf2;
					else gg[pos++] = pf2, gg[pos++] = pf1;
				}
			}
		}
		for(int i=0; i<pos-1; i++) printf("%lld ", gg[i]);
		printf("%lld\n", gg[pos-1]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}


/*
If x is not prime we know that the remaining prime factors are greater than 10^6, therefore it must have exactly two prime factors (since having 3 or more would yield a number greater than 10^18). Now we need to know whether those prime factors are equal or not, we can simply check if x is a square or not, we can do this be testing if x == pow(int(sqrt(x) + .5), 2). With these you should be able to get the number of divisors.

Is it garanteed that x == pow(int(sqrt(x) + .5), 2) works for every case (precision loss)?? I remember doing something similar and getting wrong answer, so I just iterated from sqrt(x)-5 till sqrt(x)+5 to avoid that, though probably sqrt(x) and sqrt(x)+1 are enough.
*/