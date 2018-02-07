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
const int MAX = (int)2e5+5, oo = (int)2e7+5;
int n, gain[MAX], divi[MAX];

bool Can(int score){
	return false;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d %d", &gain[i], &divi[i]);
		int i = -oo, j = oo;
		while(j - i > 1){
			int m = i + (j - i)/2;
			if(Can(m)) j = m;
			else i = m;
		}
		if(j == oo) puts("Infinity");
		else if(i == -oo) puts("Impossible");
		db(j);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
