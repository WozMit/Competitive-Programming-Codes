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
const int MAX = (int)1e6+5, m = (int)1e9+7;
int p[MAX], phi[MAX], mob[MAX], numDiv[MAX], sumDiv[MAX], inv[MAX];

void Sieve1(){
	p[0] = p[1] = -1;
	for(int i=2; i<MAX; i++) p[i] = (i&1 ? i:2);
	for(int i=3; i*i<MAX; i+=2)
		if(p[i] == i)
			for(int j=i*i; j<MAX; j+=2*i) p[j] = i;
}

void Sieve2(){
	for(int i=1; i<MAX; i++) p[i] = phi[i] = i, numDiv[i] = sumDiv[i] = 1, mob[i] = -1;
	mob[1] = inv[1] = 1;
	for(int i=2; i<MAX; i++){
		for(int j=i; j<MAX; j+=i) numDiv[j]++, sumDiv[j] += i;
		inv[i] = (m - (ll)(m/i)*inv[m%i]%m)%m;
		if(p[i] == i){
			phi[i]--;
			for(int j=i+i, isqrt = i*i; j<MAX; j+=i){
				if(i < p[j]) p[j] = i;
				phi[j] -= phi[j]/i;
				mob[j] = j%isqrt ? -mob[j/i]:0;
			}
		}
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve1();
	Sieve2();
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
