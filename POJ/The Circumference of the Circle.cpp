//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	double x1, y1, x2, y2, x3, y3;
	while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6){
		double a = hypot(x1-x3, y1-y3), b = hypot(x2-x3, y2-y3), c = hypot(x1-x2, y1-y2);
		double p = (a+b+c)/2.0, pi = 3.141592653589793;
		printf("%.2f\n", pi*a*b*c/(2*sqrt(p*(p-a)*(p-b)*(p-c))));
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
