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
const int MAX = (int)1e5+5;
int p[MAX], pfact[MAX];

void Sieve(){
	for(int i=0; i<MAX; i++) p[i] = i;
	for(int i=4; i<MAX; i+=2) p[i] = 2;
	for(int i=3; i<MAX; i+=2)
		if(p[i] == i){
			for(ll j=(ll)i*i; j<MAX; j+=2ll*i) p[j] = i;
		}
}

int Factor(int n){
	int gg = 0;
	while(n > 1){
		int pf = p[n];
		while(n%pf == 0) n /= pf;
		gg++;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	for(int i=2; i<MAX; i++) pfact[i] = Factor(i);
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b, k, gg = 0;
		scanf("%d %d %d", &a, &b, &k);
		for(; a<=b; a++) if(pfact[a] == k) gg++;
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
