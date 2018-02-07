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
const int MAX = (int)1e4+5;
int p[MAX];

void Sieve(){
	p[2] = 2, p[3] = 3, p[5] = 5;
	for(int i=4; i<MAX; i+=2) p[i] = 2;
	for(int i=9; i<MAX; i+=6) p[i] = 3;
	for(int i=25; i<MAX; i+=10) p[i] = 5;
	int w[] = {4, 2, 4, 2, 4, 6, 2, 6}, c = 0;
	for(int i=7; i*i<MAX; i += w[c++&7])
		if(!p[i]) for(int j=i*i; j<MAX; j+=2*i) p[j] = i;
	for(int i=3; i<MAX; i+=2)
		if(!p[i]) p[i] = i;
}

int d(int n){ //# of divisors of nto2
	int gg = 1;
	while(n > 1){
		int pf = p[n], k = 0;
		while(n%pf == 0) n /= pf, k++;
		gg *= 2*k+1;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	int n;
	while(scanf(" 1/%d", &n) == 1){
		printf("%d\n", (d(n)+1)/2);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
