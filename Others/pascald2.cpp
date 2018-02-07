#include <bits/stdc++.h>
using namespace std;
const int mod = 1000007;
int T[1010];

int Exp(int ex){
	if(ex == 0) return 1;
	int gg = pow(Exp(ex>>1)%mod, 2);
	if(ex%2 == 1) gg = gg<<1;
	return gg%mod;
}

int Sum(int x){
	if(x<0) return 0;
	if(x == 0) return 1;
	if(T[x] != -1) return T[x];
	return T[x] = (Exp(x)+Sum(x-1))%mod;
}

int main() {
	int x, y;
	memset(T, -1, sizeof T);
	while(scanf("%d%d", &x, &y) && !(x == -1 && y == -1)){
		int gg = Sum(y)-Sum(x-1);
		if(Sum(y) < Sum(x)) gg+=mod;
		cout << gg%mod << endl;
	}
	return 0;
}