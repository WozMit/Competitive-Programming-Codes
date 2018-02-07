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
	int te; scanf("%d", &te);
	while(te--){
		int c, d; scanf("%d %d", &c, &d);
		if((c&d) != c) printf("-1\n");
		else{
			int a = c, b = c, i = 0;
			d &= ~c;
			while(d){
				if(d&1){
					if(d == 1) b |= (1<<i);
					else a |= (1<<i);
				}
				i++;
				d >>= 1;
			}
			printf("%d %d\n", a, b);
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
