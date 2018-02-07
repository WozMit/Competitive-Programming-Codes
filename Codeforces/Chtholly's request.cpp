//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;

ll new_numb(ll x){
	ll gg = x;
	while(x > 0){
		int d = x%10;
		x = x/10;
		gg = gg*10 + d;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int k, p;
	while(scanf("%d %d", &k, &p) == 2){
		ll gg = 0ll;
		for(int i=1; i<=k; i++) gg = (gg+new_numb((ll)i))%(ll)p;
		printf("%d\n", (int)gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
