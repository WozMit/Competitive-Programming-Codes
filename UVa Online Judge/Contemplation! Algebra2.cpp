#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll M[2][2], p, q, n;

int main() {
	while(cin >> p >> q >> n){
		M[0][0] = 0;
		M[0][1] = 1;
		M[1][0] = -q;
		M[1][1] = p;
		Exp();
		cout << M[0][0]*2+M[0][1]*p << endl;
	}
	return 0;
}