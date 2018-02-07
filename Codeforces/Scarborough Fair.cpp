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
const int MAX = 105;

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	char s[MAX];
	int n, m;
	while(scanf("%d %d", &n, &m) == 2){
		scanf("%s", &s);
		while(m--){
			int l, r;
			char c1, c2; scanf("%d %d %c %c", &l, &r, &c1, &c2);
			l--, r--;
			for(; l<=r; l++)
				if(s[l] == c1) s[l] = c2;
		}
		printf("%s\n", s);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
