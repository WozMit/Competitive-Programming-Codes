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
	int q;
	while(scanf("%d", &q) == 1){
		while(q--){
			int a, b; scanf("%d %d", &a, &b);
			int gg = ceil(1.0 * b / 2.0) * (b&1 ? -1:1);
			gg -= ceil(1.0 * (a-1) / 2.0) * ((a-1)&1 ? -1:1);
			printf("%d\n", gg);
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
