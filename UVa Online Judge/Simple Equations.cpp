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
	int te;
	scanf("%d", &te);
	while(te--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		bool flag = false;
		for(int x=-100; !flag && x<101; x++)
			for(int y=x+1; !flag && y<101; y++){
				int z = a-x-y;
				if(z > y && x*y*z == b && x*x+y*y+z*z == c){
					printf("%d %d %d\n", x, y, z);
					flag = true;
				}
			}
		if(!flag) printf("No solution.\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
