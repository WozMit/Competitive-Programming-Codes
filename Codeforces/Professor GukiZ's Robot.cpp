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

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int x0, y0, x1, y1;
	while(scanf("%d %d %d %d", &x0, &y0, &x1, &y1) == 4)
		printf("%d", max(abs(x1-x0), abs(y1-y0)));
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}