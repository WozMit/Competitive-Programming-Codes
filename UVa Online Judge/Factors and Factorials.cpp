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
const int MAX = 107;
bitset<MAX> prime;
vector<int> primes;

void Sieve(){
	prime.set();
	for(int i=3; i*i<MAX; i+=2)
		if(prime[i])
			for(int j=i*i; j<MAX; j+=2*i) prime[j] = 0;
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
		printf("%3d! =", n);
		int k = 0;
		for(int i=0; primes[i]<=n; i++){
			int pf = primes[i], gg = 0, p = pf;
			while(p <= n) gg += n/p, p *= pf;
			printf("%3d", gg);
			k++;
			if(k == 15 && primes[i+1] <= n) printf("\n%6c", ' ');
			if(primes[i+1] > n) printf("\n");
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
