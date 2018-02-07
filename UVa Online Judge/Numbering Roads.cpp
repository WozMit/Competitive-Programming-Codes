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
	int r, n, t = 0;
	while(scanf("%d %d", &r, &n) == 2 && r && n){
		int gg = (r-1-((r-1)%n))/n;
		printf("Case %d: ", ++t);
		if(gg > 26) printf("impossible\n");
		else printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
