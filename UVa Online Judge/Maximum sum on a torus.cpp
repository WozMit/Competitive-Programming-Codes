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
const int MAX = 2*75+5;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te, M[MAX][MAX]; scanf("%d", &te);
	while(te--){
		int n; scanf("%d", &n);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				int x; scanf("%d", &x);
				M[i][j] = x;
			}
		int pn = 2*n;
		for(int i=0; i<n; i++)
			for(int j=n; j<pn; j++){
				M[i][j] = M[i][j-n];
				M[j][i] = M[j-n][i];
				M[i+n][j] = M[i][j-n];
			}
		for(int i=0; i<pn; i++)
			for(int j=1; j<pn; j++) M[i][j] += M[i][j-1];
		int gg = M[0][0];
		for(int i=0; i<n; i++)
			for(int l=0; l<n; l++)
				for(int j=l; j<n+l; j++){
					int gg1 = -(1<<30), max_here = gg1;
					for(int k=i; k<n+i; k++){
						int x = M[k][j]- (l ? M[k][l-1]:0);
						max_here = max(x, max_here + x);
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
