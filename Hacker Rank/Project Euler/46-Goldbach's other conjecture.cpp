    //
    //	Dear maintainer:
    // 
    // Once you are done trying to 'optimize' this routine,
    // and have realized what a terrible mistake that was,
    // please increment the following counter as a warning
    // to the next guy:
    // 
    // total_hours_wasted_here = 0
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
const int MAX = (int)5e5+5;
bitset<MAX> prime;
int GG[MAX];

void Sieve(){
	prime.set();
	prime[0] = prime[1] = false;
	for(int i=4; i<MAX; i+=2) prime[i] = false;
	for(int i=3; (ll)i*i<MAX; i+=2)
		if(prime[i]) for(ll j = i*i; j<MAX; j+=2*i) prime[j] = false;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	for(int n = 9; n<MAX; n++){
		int gg = 0;
		for(int k=1; 2*k*k<n; k++)
			if(prime[n-2*k*k]) gg++;
		GG[n] = gg;
	}
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", GG[n]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
