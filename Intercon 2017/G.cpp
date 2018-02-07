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
ll den;

ll Check(ll n){
	ll over = 1ll, gg = 0;
	while(over <= n){
		gg += n/over;
		over *= den;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		int n, k, gg = -1; scanf("%d %d", &n, &k);
		ll mini = (n+1ll)*(k-1ll)/k;
		den = k;
		for(int i=0; gg < 0 && i<31; i++)
			if(Check(mini + i) >= (ll)n) gg = (int)mini + i;
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
