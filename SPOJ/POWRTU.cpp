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
const int p = (int)1e9+7, C1 = (int)5e8+3, MAX = (int)1e5+3;
int a, b, n, f41[2*MAX], n41[2*MAX], f14[2*MAX], n14[2*MAX];

ll mul(int x, int y){ return (ll)x*y; }

void Pre(){
	f41[0] = f14[0] = 1;
	for(int i=1; i<2*MAX; i++){
		int k = 0, t = i;
		while(t%41 == 0) t /= 41, k++;
		f41[i] = f41[i-1]*t%(41*41);
		n41[i] = n41[i-1] + k;
		k = 0, t = i;
		while(t%148721 == 0) t /= 148721, k++;
		f14[i] = (ll)f14[i-1]*t%148721;
		n14[i] = n14[i-1] + k;
	}
}

int exp(ll p, int q, int m){
	int gg = 1;
	p %= m;
	if(!p) return 0;
	while(q){
		if(q&1) gg = (p*gg)%m;
		p = (p*p)%m;
		q >>= 1;
	}
	return gg;
}

int inv(int a, int m){
	int n0 = m, t, q, x0 = 0, x1 = 1;
	while(a > 1){
		q = a/m;
		t = m;
		m = a%m;
		a = t;
		t = x0;
		x0 = x1-q*x0;
		x1 = t;
	}
	if(x1 < 0) return x1 + n0;
	return x1;
}

int C(){
	int y = 0, z = 0;
	if(n41[2*n] <= 2*n41[n]+1)
		y = (n41[2*n]-2*n41[n]==1 ? 41:1)*f41[2*n]*inv(f41[n]*f41[n], 41*41) % (41*41);
	if(n14[2*n] <= 2*n14[n])
		z = (ll)f14[2*n]*exp((ll)f14[n]*f14[n], 148719, 148721)%148721;
	return ((n ? 0ll:250000001ll)+189470554ll*y+60529448ll*z)%(C1-1);
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t;
	Pre();
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &a, &b, &n);
		int c = exp(b, C(), b&1 ? p-1:C1);
		if(b%2 == 0) c = (ll)(C1+1)*c%(p-1);
		int gg = (!a && !c ? 1:exp(a, c, p));
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
