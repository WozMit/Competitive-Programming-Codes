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
const int MAX = (int)1e7+5;
int p[MAX], mob[MAX];

void Sieve(){
	for(int i=1; i<MAX; i++) p[i] = i, mob[i] = -1;
	mob[1] = 1;
	for(int i=2; i<MAX; i++)
		if(p[i] == i)
			for(int j=i+i, isqrt = i*i; j<MAX; j+=i){
				if(i < p[j]) p[j] = i;
				mob[j] = j%isqrt ? -mob[j/i]:0;
			}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	int te; scanf("%d", &te);
	while(te--){
		ll n; scanf("%lld", &n);
		ll gg = n;
		for(ll p=2; p*p<=n; p++)
			gg += mob[p]*n/(p*p);
		printf("%lld\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
