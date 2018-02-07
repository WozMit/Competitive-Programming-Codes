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
const int MAX = (int)1e6+5;
bitset<MAX> prime, truncable;
int pw10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

void Sieve(){
	prime.set();
	prime[0] = prime[1] = false;
	for(int i=4; i<MAX; i+=2) prime[i] = false;
	for(int i=3; i<MAX; i+=2)
		if(prime[i]) for(ll j=(ll)i*i; j<MAX; j+=2*i) prime[j] = false;
}

bool Truncable(int n){
	int t = n, d = 0;
	while(t/10){
		t /= 10, d++;
		if(!prime[t]) return false;
	}
	t = n;
	while(d){
		t = t%pw10[d--];
		if(!prime[t]) return false;
	}
	return true;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	int n;
	scanf("%d", &n);
	int gg = 0;
	for(int i=11; i<n; i+=2)
		if(prime[i] && Truncable(i)) gg += i;
	printf("%d\n", gg);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
