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
const int MAX1 = (int)1e5, MAX2  = (int)1e6+7;
bitset<MAX1> isprime;
bitset<MAX2> match;
vector<int> prime, p;

void Build(){
	isprime.set();
	isprime[0] = isprime[1] = false;
	for(int i=4; i<=MAX1; i+=2) isprime[i] = false;
	for(int i=3; i*i<=MAX1; i+=2)
		if(isprime[i])
			for(int j=i*i; j<=MAX1; j+=2*i) isprime[j] = false;
	prime.push_back(2);
	for(int i=3; i<=MAX1; i+=2)
		if(isprime[i]) prime.push_back(i);
}

void SegmentedSieve(int a, int b){
	match.set();
	for(int i=0; ll(prime[i])*ll(prime[i])<=ll(b); i++){
		int pr = prime[i];
		for(ll j = ceil(double(a)/pr)*pr-a; j<=b-a; j+=pr) match[j] = false;
	}
	for(int i=0; i<=b-a; i++)
		if(match[i]) p.push_back(i+a);
}

void Process(){
	if(p.size() > 1){
		int mini = 1<<30, maxi = 0, c1, c2, d1, d2;
		for(int i=1; i<p.size(); i++){
			int d = p[i]-p[i-1];
			if(d > maxi){
				maxi = d;
				d1 = p[i-1];
				d2 = p[i];
			}
			if(d < mini){
				mini = d;
				c1 = p[i-1];
				c2 = p[i];
			}
		}
		printf("%d,%d are closest, %d,%d are most distant.\n", c1, c2, d1, d2);
	}
	else printf("There are no adjacent primes.\n");
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Build();
	int a, b;
	while(scanf("%d %d", &a, &b) == 2){
		if(b <= MAX1){
			a = lower_bound(prime.begin(), prime.end(), a)-prime.begin();
			while(prime[a] <= b) p.push_back(prime[a++]);
		}
		else SegmentedSieve(a, b);
		Process();
		p.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}