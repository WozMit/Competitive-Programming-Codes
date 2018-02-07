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
const int MAX = (int)5e6+3;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	/*int pMax = 0, tMax = 0;
	int m = 0, k = 0;
	for (int s = 12; s <= MAX; s++) {
		int t = 0;
		int mlimit = sqrt(s / 2);
		for(m = 2; m <= mlimit; m++){
			if((s / 2) % m == 0){
				if (m % 2 == 0) k = m + 1;
				else k = m + 2;
				while (k < 2 * m && k <= s / (2 * m)) {
					 if (s / (2 * m) % k == 0 && __gcd(k, m) == 1) t++;
					 k += 2;
				 }
			 }
		 }
		 if(t > tMax){
			tMax = t;
			pMax = s;
			printf("%d,", pMax);
		}
	}*/
	//Pre-calculation
	int GG[] = {12,60,120,240,420,720,840,1680,2520,4620,5040,9240,18480,27720,55440,110880,120120,166320,180180,240240,360360,720720,1081080,1441440,2042040,2162160,2882880,3603600,4084080};
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int k = lower_bound(GG, GG+29, n)-GG;
		if(GG[k] != n) k--;
		printf("%d\n", GG[k]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
