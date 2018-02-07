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

int mInv(int a, int n){
	if(__gcd(a, n) != 1) return -1;
	int n0 = n, t, q, x0 = 0, x1 = 1;
	if(n == 1) return 0;
	while(a > 1){
		q = a/n;
		t = n;
		n = a%n;
		a = t;
		t = x0;
		x0 = x1-q*x0;
		x1 = t;
	}
	if(x1 < 0) x1 += n0;
	return x1;
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int a, n;
	while(scanf("%d %d", &a, &n) == 2)
		printf("Inverso modular de %d mod %d = %d.\n", a, n, mInv(a, n));
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
