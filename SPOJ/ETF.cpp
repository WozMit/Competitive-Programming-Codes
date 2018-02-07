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
const int MAX = (1e6)+5;
int p[MAX];
bitset<MAX> prime;

void MSieve(){
	prime.set();
	prime[0] = prime[1] = false;
	p[2] = 2;
	for(int i=4; i<MAX; i+=2) prime[i] = false, p[i] = 2;
	for(int i=3; i<MAX; i+=2)
		if(prime[i]){
			p[i] = i;
			for(ll j = (ll)i*(ll)i; j<MAX; j+=2ll*i)
				if(prime[j]) prime[j] = false, p[j] = i;
		}
}

int Phi(int n){
	int phi = n;
	while(n > 1){
		int pf = p[n];
		while(n%pf == 0) n /= pf;
		phi -= phi/pf;
	}
	return phi;
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	MSieve();
	int te, n;
	scanf("%d", &te);
	while(te--){
		scanf("%d", &n);
		printf("%d\n", Phi(n));
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
