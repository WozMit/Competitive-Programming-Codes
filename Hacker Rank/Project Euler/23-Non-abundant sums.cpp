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
const int MAX = (int)1e5+7, limit = 28123;
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
	vector<int> V;
	for(int i=12; i<=limit; i++)
		if(d(i) > i) V.push_back(i);
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		bool flag = false;
		if(n > limit) flag = true;
		for(int i=0; !flag && i<V.size(); i++)
			if(binary_search(V.begin(), V.end(), n-V[i])) flag = true;
		cout << (flag ? "YES":"NO") << endl;
	}
	#ifdef WozMit
		//printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s";
	#endif
	return 0;
}
