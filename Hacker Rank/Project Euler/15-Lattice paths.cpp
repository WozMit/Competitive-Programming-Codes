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
const ll p = (ll)1e9+7;
const int MAX = 2*505;
int f[MAX];

int exp(int a, int b){
	int gg = 1;
	while(b){
		if(b&1) gg = ((ll)gg*a)%p;
		a = ((ll)a*a)%p;
		b >>= 1;
	}
	return gg;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	f[0] = 1;
	for(int i=1; i<MAX; i++) f[i] = ((ll)i*f[i-1])%p;
	int t, n, m;
	cin >> t;
	while(t--){
		cin >> n >> m;
		cout << (((ll)f[n+m]*exp(f[n], p-2))%p*exp(f[m], p-2))%p << "\n";
	}
	#ifdef WozMit
		//printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s";
	#endif
	return 0;
}
