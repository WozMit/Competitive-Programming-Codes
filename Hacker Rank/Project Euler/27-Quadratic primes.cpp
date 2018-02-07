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
#define db(x) cout << #x << " = " << x << "\n"
using namespace std;
const int MAX = (int)1e7;
bitset<MAX> prime;

void Sieve(){
	prime.set();
	prime[0] = prime[1] = 0;
	for(int i=4; i<MAX; i+=2) prime[i] = 0;
	for(int i=3; i*i<MAX; i+=2)
		if(prime[i])
			for(int j=i*i; j<MAX; j+=2*i) prime[j] = 0;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	int n;
	while(scanf("%d", &n) == 1){
		int gg = -1, ga, gb;
		for(int b=0; b<=n; b++)
			if(prime[b])
				for(int a=-b; a<=n; a++)
					for(int k=0; ; k++){
						int p = k*k+a*k+b;
						if(p <=0 || !prime[p]){
							if(k > gg){
								gg = k;
								ga = a;
								gb = b;
							}
							break;
						}
					}
		printf("%d %d\n", ga, gb);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s";
	#endif
	return 0;
}
