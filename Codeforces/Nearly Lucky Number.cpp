//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

bool Lucky(int x){
	if(!x) return false;
	while(x){
		int k = (int) x%10;
		if(k != 4 && k != 7) return false;
		x /= 10;
	}
	return true;
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	ll n;
	while(scanf("%I64d", &n) == 1){
		int ldigits = 0;
		while(n){
			int k = (int)(n%10ll);
			if(k == 4 || k == 7) ldigits++;
			n /= 10ll;
		}
		if(Lucky(ldigits)) printf("YES\n");
		else printf("NO\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}