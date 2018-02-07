#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll Exp(ll a, ll b){
	if(b == 0ll) return 1ll;
	ll gg = Exp(a, b>>1ll);
	gg *= gg;
	if(b&1ll) return a*gg;
	return gg;
}

ll D(int n){
	ll a = 0, c = n;
	while(n%2 == 0){
		n /= 2;
		a++;
	}
	ll gg = (1ll<<(a+1))-1ll;
	ll k = 3ll;
	while(k*k <= n){
		a = 0;
		while(n%k == 0ll){
			n /= k;
			a++;
		}
		gg *= (Exp(k, a+1)-1)/(k-1ll);
		k += 2ll;
	}
	if(n > 1) gg *= n+1ll;
	return gg - c;
}
int main() {
	set<ll> S;
	for(ll i=2ll; i<=10000ll; i++){
		ll b = D(i);
		if(b != i && D(b) == i){
			S.insert(b);
			S.insert(i);
		}
	}
	vector<ll> V(S.begin(), S.end());
	ll gg = 0;
	for(int i=0; i<V.size(); i++) gg += V[i];
	cout << gg << endl;
	return 0;
}