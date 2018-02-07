//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n"
using namespace std;
typedef long long int ll;
const ll oo = 1ll<<62ll;
int n, b, P[801];
ll P1[801];
vector<int> F;

void Factor(int b){
	memset(P, 0, sizeof P);
	int k = 0;
	while(b%2 == 0) b >>= 1, k++;
	if(k) F.push_back(2), P[2] = k;
	for(int i=3; i*i<=b; i+=2){
		k = 0;
		while(b%i == 0) b /= i, k++;
		if(k) F.push_back(i), P[i] = k;
	}
	if(b > 1) F.push_back(b), P[b] = 1;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &b) == 2){
		Factor(b);
		memset(P1, 0ll, sizeof P1);
		double d = 1;
		for(int i=2; i<=n; i++){
			d += log(i)/log(b);
			int a = i;
			for(int j=0; j<F.size(); j++){
				int p = F[j];
				ll k = 0ll;
				while(a%p == 0) a /= p, k++;
				P1[p] += k;
			}
		}
		ll gg = oo;
		for(int i=0; i<F.size(); i++) gg = min(gg, P1[F[i]]/P[F[i]]);
		printf("%lld %d\n", gg, (int)d);
		F.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
