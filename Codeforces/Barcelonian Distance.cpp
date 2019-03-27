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

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	double a, b, c, x1, y1, x2, y2;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf", &a, &b, &c, &x1, &y1, &x2, &y2) == 7){
		double gg = fabs(x1 - x2) + fabs(y1 - y2);
		if(a != 0.0 && b != 0.0){
			double c1 = 0.0, c2 = 0.0;
			if(x1 > x2){
				swap(x1, x2);
				swap(y1, y2);
			}
			double interx1 = (-c-a*x1) / b;
			double interx2 = (-c-a*x2) / b;
			double intery1 = (-c-b*y1) / a;
			double intery2 = (-c-b*y2) / a;
			if(y2 > y1){
				if(interx1 >= y1 && interx1 <= y2 && intery2 >= x1 && intery2 <= x2){
					c1 = y2 - interx1;
					c2 = intery2 - x1;
				}
				if(intery1 >= x1 && intery1 <= x2 && interx2 >= y1 && interx2 <= y2){
					c1 = x2 - intery1;
					c2 = interx2 - y1;
				}
				if(intery1 < intery2 && intery1 >= x1 && intery1 <= x2 && intery2 >= x1 && intery2 <= x2){
					c1 = intery2 - intery1;
					c2 = y2 - y1;
				}
				if(interx1 < interx2 && interx1 >= y1 && interx1 <= y2 && interx2 >= y1 && interx2 <= y2){
					c1 = interx2 - interx1;
					c2 = x2 - x1;
				}
			}
			else if(y1 > y2){
				if(interx1 >= y2 && interx1 <= y1 && intery2 >= x1 && intery2 <= x2){
					c1 = interx1 - y2;
					c2 = intery2 - x1;
				}
				if(intery1 >= x1 && intery1 <= x2 && interx2 >= y2 && interx2 <= y1){
					c1 = x2 - intery1;
					c2 = y1 - interx2;
				}
				if(intery1 < intery2 && intery1 >= x1 && intery1 <= x2 && intery2 >= x1 && intery2 <= x2){
					c1 = intery2 - intery1;
					c2 = y1 - y2;
				}
				if(interx1 > interx2 && interx1 >= y2 && interx1 <= y1 && interx2 >= y2 && interx2 <= y1){
					c1 = interx1 - interx2;
					c2 = x2 - x1;
				}
			}
			gg += hypot(c1, c2) - c1 - c2;
		}
		printf("%.10lf\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
