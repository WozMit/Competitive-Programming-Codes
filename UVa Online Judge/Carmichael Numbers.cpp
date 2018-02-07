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
#define db(x) cout << #x << " = " << x << "\n"
using namespace std;
typedef long long int ll;
const int MAX = 65007;
bitset<MAX> prime;

void Sieve(){
	prime.set();
	prime[0] = prime[1] = 0;
	for(int i=4; i<MAX; i+=2) prime[i] = 0;
	for(int i=3; i*i<MAX; i+=2)
		if(prime[i])
			for(int j=i*i; j<MAX; j+=2*i) prime[j] = 0;
}

int exp(int a, int b, int m){
	int gg = 1;
	while(b){
		if(b&1) gg = (int)(((ll)gg*a)%(ll)m);
		a = (int)(((ll)a*a)%(ll)m);
		b >>= 1;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	int n;
	while(scanf("%d", &n) == 1 && n){
		bool flag = !prime[n];
		for(int i=2; flag && i<n; i++)
			if(exp(i, n, n) != i) flag = false;
		if(flag) printf("The number %d is a Carmichael number.\n", n);
		else printf("%d is normal.\n", n);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
