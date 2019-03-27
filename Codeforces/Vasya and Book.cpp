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

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		ll n, x, y, d; scanf("%I64d %I64d %I64d %I64d", &n, &x, &y, &d);
		ll gg = (ll)1e16;
		if((y - 1) % d == 0)
			gg = (x + d - 2) / d + (y - 1) / d;
		if(abs(x - y) % d == 0)
			gg = min(gg, abs(x - y) / d);
		if((n - y) % d == 0)
			gg = min(gg, (n - x + d - 1) / d +  (n - y) / d);
		if(gg == (ll)1e16) puts("-1");
		else printf("%I64d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
