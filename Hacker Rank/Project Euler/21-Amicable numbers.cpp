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
#include <set>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
const int MAX = (int)1e6+7, MAX1 = (int)1e5;
bitset<MAX> prime;
int p[MAX];

void Sieve(){
	prime.set();
	prime[0] = prime[1] = false;
	p[2] = 2;
	for(int i=4; i<MAX; i+=2) prime[i] = false, p[i] = 2;
	for(int i=3; i<MAX; i+=2){
		if(prime[i]){
			p[i] = i;
			for(ll j = (ll)i*i; j<MAX; j+=2ll*i)
				if(prime[j]) prime[j] = false, p[j] = i;
		}
	}
}

int pow(int a, int b){
	int gg = 1;
	while(b){
		if(b&1) gg *= a;
		a *= a;
		b >>= 1;
	}
	return gg;
}

int d(int h){
	int gg = 1, n = h;
	while(n > 1){
		int pf = p[n], k = 0;
		while(n%pf == 0) n /= pf, k++;
		gg *= (pow(pf, k+1)-1)/(pf-1);
	}
	return gg-h;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	set<int> S;
	for(int i=2; i<MAX1; i++){
		int p = d(i);
		if(i != p && d(p) == i) S.insert(i), S.insert(p);
	}
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int gg = 0;
		for(set<int>::iterator i=S.begin(); i!=S.end(); i++)
			if(*i < n) gg += *i;
		cout << gg << "\n";
	}
	#ifdef WozMit
		//printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s";
	#endif
	return 0;
}
