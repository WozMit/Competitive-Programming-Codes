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
const int MAX = 105;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, M[MAX][MAX];
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				int x; scanf("%d", &x);
				M[i][j] = x + (j ? M[i][j-1]:0);
			}
		int gg = M[0][0];
		for(int l=0; l<n; l++)
			for(int j=l; j<n; j++){
				int gg1 = M[0][j] - (l ? M[0][l-1]:0), max_here = gg1;
				for(int i=0; i<n; i++){
					int x = M[i][j] - (l ? M[i][l-1]:0);
					max_here = max(x, x + max_here);
					gg1 = max(gg1, max_here);
				}
				gg = max(gg, gg1);
			}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
