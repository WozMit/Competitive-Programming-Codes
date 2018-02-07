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
const int MAX = 105, oo = 1<<30;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t, M[MAX][MAX]; scanf("%d", &t);
	for(int te=0; te<t; te++){
		int n, m, k; scanf("%d %d %d", &n, &m, &k);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){
				int x; scanf("%d", &x);
				M[i][j] = x + (j ? M[i][j-1]:0);
			}
		int gga = 0, ggp = 1<<30;
		for(int l=0; l<m; l++)
			for(int j=l; j<m; j++){
				int A[n];
				for(int i=0; i<n; i++) A[i] = M[i][j] - (l ? M[i][l-1]:0);
				int i1 = 0, i2 = 0, sum_here = 0, area = 0, gg1 = oo;
				while(i2 < n){
					sum_here += A[i2++];
					while(sum_here > k) sum_here -= A[i1++];
					if(i2-i1 == area && sum_here < gg1) gg1 = sum_here;
					else if(i2-i1 > area) area = i2-i1, gg1 = sum_here;
				}
				area *= (j-l+1);
				if(area > gga) gga = area, ggp = gg1;
				else if(gga == area && gg1 < ggp) ggp = gg1;
			}
		printf("Case #%d: %d %d\n", te+1, gga, ggp);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
