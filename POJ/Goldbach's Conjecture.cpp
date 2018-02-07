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
const int MAX = (int)1e6+5;
bitset<MAX> prime;
vector<int> primes;

void Sieve(){
	prime.set();
	for(int i=4; i<MAX; i+=2) prime[i] = false;
	for(int i=3; i*i<MAX; i+=2)
		if(prime[i]) for(int j=i*i; j<MAX; j+=2*i) prime[j] = false;
	for(int i=3; i<MAX; i++)
		if(prime[i]) primes.push_back(i);
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	int n;
	while(scanf("%d", &n) && n){
		int i = 0;
		while(1) if(prime[n-primes[i++]]) break;
		printf("%d = %d + %d\n", n, primes[i-1], n-primes[i-1]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
