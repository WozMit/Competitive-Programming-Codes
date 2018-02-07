//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
const ll MAX = 1000000000000000000;

ll Exp(ll a, ll b){
	if(b == 0ll) return 1ll;
	ll gg = Exp(a, b>>1ll);
	gg *= gg;
	if(b&1ll) return a*gg;
	return gg;
}

int main() {
	ll i, j, r;
	while(cin >> i >> j >> r){
		ll k = ll(ceil(log(double(i))/log(double(r))));
		ll gg = double(double(k)*log10(double(r))) > 18.0 ? MAX+5:Exp(r, k);
		int cont = 0;
		while(gg >= i && gg <= j){
			cout << gg << " ";
			cont++;
			if(gg > MAX/r) break;
			gg *= r;
		}
		if(!cont) cout << "-1" << endl;
		else cout << endl;
	}
	return 0;
}