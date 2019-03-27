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
	string s;
	while(cin >> s){
		int r = ceil(1.0 * s.size() / 20);
		int c = ceil(1.0 * s.size() / r);
		int ast = r * c - s.size();
		char M[r][c];
		int k = 0;
		printf("%d %d\n", r, c);
		for(int i=0; i<r; i++){
			int to = ast / r + (i + 1 <= (ast % r) ? 1 : 0), j;
			for(j=0; j<c-to; j++) printf("%c", s[k++]);
			for(; j<c; j++) printf("*");
			printf("\n");
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
