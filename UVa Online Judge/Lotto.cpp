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
int n, A[15];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	bool flag = false;
	while(scanf("%d", &n) == 1 && n){
		if(flag) printf("\n");
		else flag = true;
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		sort(A, A+n);
		for(int a=0; a<n-5; a++)
			for(int b=a+1; b<n-4; b++)
				for(int c=b+1; c<n-3; c++)
					for(int d=c+1; d<n-2; d++)
						for(int e=d+1; e<n-1; e++)
							for(int f=e+1; f<n; f++)
								printf("%d %d %d %d %d %d\n", A[a], A[b], A[c], A[d], A[e], A[f]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
