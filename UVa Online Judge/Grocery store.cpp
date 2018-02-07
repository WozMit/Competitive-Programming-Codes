//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <set>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	for(int a=1; a<2001 && (ll)a*a*a*a<=2000000000ll; a++)
		for(int b=a; b<2001-a && (ll)a*b*b*b<=2000000000ll; b++)
			for(int c=b; c<2001-a-b && (ll)a*b*c*c<=2000000000ll; c++){
				ll prod = a*b*c, sum = a+b+c;
				if(prod-1000000ll != 0 && (1000000ll*sum)%(prod-1000000ll) == 0ll){
					int d = 1000000ll*sum/(prod-1000000ll);
					if(c <= d && sum+d<=2000 && prod*d<=2000000000ll){
						printf("%.2f %.2f %.2f %.2f\n", a/100.0, b/100.0, c/100.0, d/100.0);
					}
				}
			}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
