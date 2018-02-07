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
const int MAX = (int)1e5+7;
bitset<MAX> isprime, match;
vector<int> prime;

void Build(){
	isprime.set();
	isprime[0] = isprime[1] = false;
	for(int i=4; i<=MAX; i+=2) isprime[i] = false;
	for(int i=3; i*i<=MAX; i+=2)
		if(isprime[i])
			for(int j=i*i; j<=MAX; j+=2*i) isprime[j] = false;
	prime.push_back(2);
	for(int i=3; i<=MAX; i+=2)
		if(isprime[i]) prime.push_back(i);
}

void segmentedSieve(int a, int b){
	match.set();
	for(int i=0; ll(prime[i])*ll(prime[i])<=ll(b); i++){
		int p = prime[i];
		for(ll j = ceil(double(a)/p)*p-a; j<=b-a; j+=p) match[j] = false;
	}
	for(int i=0; i<=b-a; i++)
		if(match[i]) printf("%d\n", i+a);
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Build();
	int t, a, b;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &a, &b);
		if(b <= MAX){
			a = lower_bound(prime.begin(), prime.end(), a)-prime.begin();
			while(prime[a] <= b) printf("%d\n", prime[a++]);
		}
		else segmentedSieve(a, b);
		printf("\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}