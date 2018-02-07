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
	int N[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, x, y;
	while(scanf("%d %d", &x, &y) == 2){
		int gg = 0;
		for(x; x<=y; x++){
			int i = x;
			while(i){
				gg += N[i%10];
				i /= 10;
			}
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}