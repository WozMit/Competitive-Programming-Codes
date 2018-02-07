//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <bitset>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = 2680;
bitset<MAX> prime;
int p[MAX];
vector<int> GG;

void Sieve(){
	prime.set();
	prime[0] = prime[1] = 0;
	p[2] = 2;
	for(int i=4; i<MAX; i+=2) prime[i] = 0, p[i] = 2;
	for(int i=3; i<MAX; i+=2)
		if(prime[i]){
			p[i] = i;
			for(int j= i*i; j<MAX; j+=2*i)
				if(prime[j]) prime[j] = 0, p[j] = i;
		}
}

bool IsLucky(int n){
	int gg = 1, nfactors = 0;
	while(n > 1){
		int pf = p[n];
		while(n%pf == 0) n /= pf;
		nfactors++;
		if(nfactors == 3) return true;
	}
	return false;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	for(int i=30; i<MAX; i++)
		if(IsLucky(i)) GG.push_back(i);
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", GG[n-1]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
