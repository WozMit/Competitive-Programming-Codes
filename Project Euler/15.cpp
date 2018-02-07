#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ll n = 20ll, m = 20ll, C[21][21];
	//C(n+m, n)
	for(ll i=0ll; i<=n+m; i++){
		for(ll j=0ll; j<=n; j++){
			if(!j) C[i][j] = 1ll;
			else if(!i) C[i][j] = 0ll;
			else C[i][j] = C[i-1ll][j-1ll]+C[i-1ll][j];
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	cout << C[n][m] << endl;
	//137846528820
	return 0;
}