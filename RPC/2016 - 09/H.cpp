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
	int t, A[5];
	scanf("%d", &t);
	for(int te=0; te<t; te++){
		for(int i=0; i<5; i++) scanf("%d", &A[i]);
		while(A[0] < 0 || A[1] < 0 || A[2] < 0 || A[3] < 0 || A[4] < 0){
			int mini = 1<<30, gg = 0;
			for(int i=0; i<5; i++) if(A[i] < mini) mini = A[i], gg = i;
			A[(gg+4)%5] += A[gg], A[(gg+6)%5] += A[gg];
			A[gg] = -A[gg];
		}
		printf("Pentagon #%d:\n%d %d %d %d %d\n", te+1, A[0], A[1], A[2], A[3], A[4]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
