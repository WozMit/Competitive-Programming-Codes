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
	int n;
	while(scanf("%d", &n) == 1){
		int gg1 = 0, gg2 = 0, s1 = 0, s2 = 0;
		while(n--){
			int x, y; scanf("%d %d", &x, &y);
			s1 += x; s2 += y;
			if(s1 > s2) gg1 = max(gg1, s1 - s2);
			else gg2 = max(gg2, s2 - s1);
		}
		if(gg1 > gg2) printf("1 %d\n", gg1);
		else printf("2 %d\n", gg2);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
