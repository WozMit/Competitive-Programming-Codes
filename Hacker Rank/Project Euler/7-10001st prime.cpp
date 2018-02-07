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
const int MAX = (int)1e6+5;
bitset<MAX> p;
vector<int> prime;

void Sieve(){
	p.set();
	p[0] = p[1] = false;
	prime.push_back(2);
	for(int i=4; i<MAX; i+=2) p[i] = false;
	for(int i=3; i<MAX; i+=2){
		if(p[i]) prime.push_back(i);
		for(ll j=(ll)i*i; j<MAX; j+=2ll*i) p[j] = false;
	}
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t, n;
	scanf("%d", &t);
	Sieve();
	while(t--){
		scanf("%d", &n);
		printf("%d\n", prime[n-1]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
