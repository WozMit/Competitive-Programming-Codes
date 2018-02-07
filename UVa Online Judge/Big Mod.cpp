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

int Exp(int a, int b, int m){
	int gg = 1;
	while(b){
		if(b&1) gg = (gg*a)%m;
		a = (a*a)%m;
		b >>= 1;
	}
	return gg;
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int a, b, m;
	while(scanf("%d %d %d", &a, &b, &m) == 3)
		printf("%d\n", Exp(a%m, b, m));
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
