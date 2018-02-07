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
ll p; int k;

ll mul(ll a, ll b){
	ll gg = 0ll;
	while(b > 0ll){
		if(b&1ll) gg = (gg + a)%p;
		a = (a*2ll)%p;
		b >>= 1ll;
	}
	return gg;
}

struct matrix{
	ll M[16][16];
	matrix(){
		memset(M, 0, sizeof M);
		M[0][0] = 1;
		for(int i=0; i<k; i++) M[i][i+1] = 1;
	}
	matrix operator *(matrix A)const{
		matrix GG;
		for(int i=0; i<=k; i++)
			for(int j=0; j<=k; j++){
				ll sum = 0ll;
				for(int h=0; h<=k; h++) sum = 
				(sum + mul(M[i][h], A.M[h][j])%p)%p;
				GG.M[i][j] = sum;
			}
		return GG;
	}
};

matrix Exp(matrix A, ll b){
	matrix GG;
	memset(GG.M, 0, sizeof GG.M);
	for(int i=0; i<=k; i++) GG.M[i][i] = 1, A.M[k][i] %= p;
	while(b != 0ll){
		if(b&1ll) GG = GG*A;
		A = A*A;
		b >>= 1ll;
	}
	return GG;
}

int main() {
	std::ios::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te, B[16];
	scanf("%d", &te);
	while(te--){
		scanf("%d", &k);
		matrix T = matrix();
		for(int i=0; i<k; i++) scanf("%d", &B[i+1]);
		for(int i=k; i>0; i--) scanf("%lld", &T.M[k][i]);
		ll m, n;
		scanf("%lld %lld %lld", &m, &n, &p);
		matrix Tm = Exp(T, m-1), Tn = Exp(T, n);
		ll Gm = 0ll, Gn = 0ll;
		for(int i=1; i<=k; i++){
			Gm = (Gm + mul(Tm.M[0][i], (ll)B[i]) )%p;
			Gn = (Gn + mul(Tn.M[0][i], (ll)B[i]) )%p;
		}
		ll gg = ((Gn-Gm)%p+p)%p;
		printf("%lld\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
