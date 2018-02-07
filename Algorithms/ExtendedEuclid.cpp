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
int x, y, d;

void GCD(int a, int b){
	if(!b){
		d = a;
		x = 1;
		y = 0;
	}
	else{
		GCD(b, a%b);
		int temp = x;
		x = y;
		y = temp-(a/b)*y;
	}
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int a, b;
	while(scanf("%d %d", &a, &b) == 2){
		GCD(a, b);
		printf("%d(%d)+%d(%d)=%d\n", a, x, b, y, d);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
