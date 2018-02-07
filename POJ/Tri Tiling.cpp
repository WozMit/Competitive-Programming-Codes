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
	while(scanf("%d", &n) == 1 && n != -1){
		int fimt = 1, aimt = 1, fim = 1, aim = 1, fi = 1, ai = 1, t1, t2;
		for(int i=1; i<n; i++){
			fi = fimt+2*aim;
			ai = fim+aimt;
			fimt = fim, aimt = aim;
			fim = fi, aim = ai;
		}
		printf("%d\n", n&1 ? 0:fi);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
