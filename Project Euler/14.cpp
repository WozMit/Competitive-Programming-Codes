#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll Chain(ll n){
	ll k = 1ll;
	while(n > 1){
		if(n&1) n = 3ll*n+1ll;
		else n /= 2ll;
		k++;
	}
	return k;
}

int main() {
	ll gg, great = 0;
	for(ll i = 1ll; i<1000000ll; i++){
		ll x = Chain(i);
		if(x > great){
			great = x;
			gg = i;
		}
	}
	cout << gg << endl;
	return 0;
}