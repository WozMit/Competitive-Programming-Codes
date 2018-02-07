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
const int MAX = (int)1e5;
bitset<MAX> prime;
vector<int> primes;

void Sieve(){
	prime.set();
	for(int i=4; i<MAX; i+=2) prime[i] = false;
	for(int i=3; i*i<MAX; i+=2)
		if(prime[i]) for(int j=i*i; j<MAX; j+=2*i) prime[j] = false;
	primes.push_back(2);
	for(int i=3; i<MAX; i+=2)
		if(prime[i]) primes.push_back(i);
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	int n;
	while(scanf("%d", &n) == 1 && n){
		printf("%d = ", n);
		bool flag = false;
		if(n < 0) printf("-1"), n = -n, flag = true;
		for(int i=0; n>1 && (ll)primes[i]*primes[i]<=n; i++){
			int p = primes[i];
			while(n%p == 0)
				if(flag) printf(" x %d", p), n /= p;
				else printf("%d", p), n /= p, flag = true;
		}
		if(n > 1)
			if(flag) printf(" x %d", n);
			else printf("%d", n);
		printf("\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
