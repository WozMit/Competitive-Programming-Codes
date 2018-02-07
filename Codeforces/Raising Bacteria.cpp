#include <iostream>
using namespace std;
typedef long long int ll;

ll solve(ll x){
	if(x == 1) return 1;
	return solve(x/2) + (x&1 ? 1:0);
}

int main() {
	ll x;
	while(cin >> x){
		ll gg = solve(x);
		cout << gg << endl;
	}
	return 0;
}