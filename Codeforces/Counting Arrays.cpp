//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = (int)1e6+20, p = (int)1e9+7;
int divi[MAX], f[MAX];

void Sieve(){
	divi[0] = divi[1] = -1;
	for(int i=2; i<MAX; i++) divi[i] = (i&1 ? i:2);
	for(int i=3; i*i<MAX; i+=2)
		if(divi[i] == i)
			for(int j=i*i; j<MAX; j+=2*i) divi[j] = i;
}

int exp(int a, int b){
	int gg = 1;
	while(b){
		if(b&1) gg = (ll)gg*a%p;
		a = (ll)a*a%p;
		b >>= 1;
	}
	return gg;
}

int C(int n, int k){
	return (ll)f[n] * exp(f[n-k], p-2)%p *exp(f[k], p-2)%p;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	f[0] = 1;
	for(int i=1; i<MAX; i++) f[i] = (ll)i*f[i-1]%p;
	int te; scanf("%d", &te);
	while(te--){
		int x, y; scanf("%d %d", &x, &y);
		int gg = exp(2, y-1);
		while(x > 1){
			int pf = divi[x], e = 0;
			while(x%pf == 0) x /= pf, e++;
			gg = (ll)gg*C(e+y-1, y-1)%p;
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
