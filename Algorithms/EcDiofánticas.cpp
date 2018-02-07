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
int xp, yp, d, x, y;

void GCD(int a, int b){
	if(!b){
		d = a;
		xp = 1;
		yp = 0;
	}
	else{
		GCD(b, a%b);
		int temp = xp;
		xp = yp;
		yp = temp-(a/b)*yp;
	}
}

void PartSol(int a, int b, int n){
	GCD(a, b);
	x = n*xp/d;
	y = n*yp/d;
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int a, b, n;
	while(scanf("%d %d %d", &a, &b, &n) == 3){
		PartSol(a, b, n);
		printf("Soluciones particulares:\n");
		printf("x0 = %d, y0 = %d\n", x, y);
		printf("%d(%d)+%d(%d)=%d.\n", a, x, b, y, n);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
