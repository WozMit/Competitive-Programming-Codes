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
		int x, sum = 0, maxdepth = 0, posdepth, maxcont = 0, ggcount, poscont, count = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &x);
			sum += (x&1 ? 1:-1);
			if(sum > maxdepth) maxdepth = sum, posdepth = i+1;
			if(x == 1 && sum == 1) poscont = i+1, count = 1;
			if(sum > 0) count++;
			else if(count > maxcont) maxcont = count, ggcount = poscont;
		}
		printf("%d %d %d %d", maxdepth, posdepth, maxcont, ggcount);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
