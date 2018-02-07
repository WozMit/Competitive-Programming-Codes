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

int lcm(int a, int b){ return a*(b/__gcd(a, b)); }

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int gg = 1;
		for(int i=2; i<=n; i++) gg = lcm(gg, i);
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
