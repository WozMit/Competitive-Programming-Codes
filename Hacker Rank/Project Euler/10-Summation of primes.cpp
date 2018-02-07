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
#define pb push_back
const int MAX = (int)1e6+5;
bitset<MAX> prime;
vector<int> primes;

void Sieve(){
	prime.set();
	prime[0] = prime[1] = false;
	for(int i=4; i<MAX; i+=2) prime[i] = false;
	for(int i=3; i*i<MAX; i+=2)
		for(ll j = (ll)i*i; j<MAX; j+=2ll*i) prime[j] = false;
	primes.pb(2);
	for(int i=3; i<MAX; i+=2)
		if(prime[i]) primes.pb(i);
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ll gg = 0ll;
		for(int i=0; primes[i]<=n; i++) gg += (ll)primes[i];
		printf("%lld\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
