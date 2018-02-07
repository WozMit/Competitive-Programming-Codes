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
	int n, c, s;
	while(scanf("%d %d %d", &n, &c, &s) == 3){
		int pos = 1, gg = (s == 1) ? 1:0;
		while(c--){
			int x; scanf("%d", &x);
			if(x == 1) pos = (pos == n) ? 1:pos+1;
			else pos = (pos == 1) ? n:pos-1;
			if(pos == s) gg++;
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
