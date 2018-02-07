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
	int t, n, x;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int gg = 1;
		double ln = 0.0;
		while(n--){
			scanf("%d", &x);
			gg = (gg*x)%10;
			ln += log10(x);
		}
		printf("%d %d\n", (int)pow(10, ln-(int)ln), gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}