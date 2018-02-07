//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int p = 1009;
int Co[p+5][p+5];

int exp(int a, int b){
	int gg = 1;
	while(b){
		if(b&1) gg = gg*a%p;
		a = a*a%p;
		b >>= 1;
	}
	return gg;
}

int C(ll n, ll k){
	int gg = 1;
	while(n){
		gg = gg*Co[n%p][k%p]%p;
		n /= p, k /= p;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	/*f[0] = 1;
	for(int i=1; i<p+5; i++)
		if(i%p) f[i] = f[i-1]*i%p;*/
	for(int i=0; i<p+5; i++) Co[i][0] = 1;
	for(int i=1; i<p+5; i++)
		for(int j=1; j<p+5; j++) Co[i][j] = (Co[i-1][j] + Co[i-1][j-1])%p;
	int te; scanf("%d", &te);
	while(te--){
		ll n, k; scanf("%lld %lld", &n, &k);
		printf("%d\n", C(n, k));
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
