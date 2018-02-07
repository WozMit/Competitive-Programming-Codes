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
	if(n == 2ll) return true;
	if(n < 2 || (n&1) == 0) return false;
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
	if((n&1) == 0) return 2ll;
	if(n == 1ll || Miller_Rabin(n)) return n;
	srand(time(NULL));
	ll a = (rand()%(n-1))+1, b = (rand()%(n-1))+1;
	ll x = 2ll, y = 2ll, d;
	do{
		x = (x*(x+a)+b)%n;
		y = (y*(y+a)+b)%n;
		y = (y*(y+a)+b)%n;
		d = __gcd(abs(x-y), n);
	}while(d == 1ll);
	return d;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	ll n;
	while(scanf("%lld", &n) == 1){
		ll pf = Pollards_Rho(n);
		printf("%lld is a prime factor of %lld\n", pf, n);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}

/*
Input:
1
2
3
4
5
6
7
8
9
11
13
17
21
50
1000000007
1000007
961748941
982451653
829335464115266369
1777890554544646525
*/