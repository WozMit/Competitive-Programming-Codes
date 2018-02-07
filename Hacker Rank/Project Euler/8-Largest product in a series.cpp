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
	std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t, n, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		char s[n];
		scanf("%s", s);
		int gg = 0;
		for(int i=0; i<n-k+1; i++){
			int act = 1;
			for(int j=0; j<k; j++) act *= s[i+j]-'0';
			gg = max(gg, act);
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
