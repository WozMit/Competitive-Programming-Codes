//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t;
	scanf("%lld", &t);
	while(t--){
		ll n, gg = 1;
		scanf("%lld", &n);
		for(ll i = 2; i*i<=n; i++){
			if(n%i == 0) gg = i;
			while(n % i == 0) n /= i;
		}
		if(n > 1) gg = n;
		printf("%lld\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
