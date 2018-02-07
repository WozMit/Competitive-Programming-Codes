    //
    //	Dear maintainer:
    // 
    // Once you are done trying to 'optimize' this routine,
    // and have realized what a terrible mistake that was,
    // please increment the following counter as a warning
    // to the next guy:
    // 
    // total_hours_wasted_here = 0
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
const int MAX = (int)1e7;
bitset<MAX> prime;
vector<int> primes; // 664579 primes
ll S[664579], n;
int GG[MAX], t;

void Sieve(){
	prime.set();
	prime[0] = prime[1] = false;
	for(int i=4; i<MAX; i+=2) prime[i] = false;
	for(int i=3; (ll)i*i<MAX; i+=2)
		if(prime[i]) for(ll j=i*i; j<MAX; j+=2*i) prime[j] = false;
	primes.push_back(2);
	for(int i=3; i<MAX; i+=2) if(prime[i]) primes.push_back(i);
	S[0] = 2ll;
	for(int i=1; i<664579; i++) S[i] = S[i-1] + primes[i];
}

bool Is_prime(ll n){
	if(n < MAX) return prime[n];
	for(ll i=2ll; i*i<=n; i++)
		if(n%i == 0) return false;
	return true;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		int idx = lower_bound(S, S+664579, n)-S;
		ll gg1 = 0, gg2 = 0;
		for(int i=max(0, idx-20); i<min(idx+20, 664579); i++)
			for(int j=0; j<100 && j<=i-gg2; j++){
				ll sum = S[i] - (j ? S[j-1]:0);
				if(sum <= n && Is_prime(sum)){
					int len = i-j+1;
					if(len > gg2) gg1 = sum, gg2 = len;
				}
			}
		printf("%lld %lld\n", gg1, gg2);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}