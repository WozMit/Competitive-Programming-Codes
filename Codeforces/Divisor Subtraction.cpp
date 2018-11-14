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
	ll n;
	while(scanf("%lld", &n) == 1){
		bool flag = false;
		if(n%2ll == 0ll){
			printf("%I64d\n", n / 2);
			flag = true;
		}
		for(int i=3; !flag && (ll)i*i<=n; i+=2)
			if(n%i == 0){
				printf("%I64d\n", (n - i) / 2L + 1L);
				flag = true;
			}
		if(!flag) puts("1");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
