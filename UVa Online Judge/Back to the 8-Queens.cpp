//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
int A[] = {1, 2, 3, 4, 5, 6, 7, 8}, S[92][8], I[8];

bool Check(){
	for(int i=0; i<8; i++)
		for(int j=i+1; j<8; j++)
			if(abs(A[i]-A[j]) == abs(i-j)) return false;
	return true;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int j = 0;
	do{
		if(Check()){ for(int i=0; i<8; i++) S[j][i] = A[i]; j++; }
	}while(next_permutation(A, A+8));
	int te = 0;
	while(scanf("%d", &I[0]) == 1){
		scanf("%d %d %d %d %d %d %d", &I[1], &I[2], &I[3], &I[4], &I[5], &I[6], &I[7]);
		int gg = 10;
		for(int i=0; i<92; i++){
			int sum = 0;
			for(int j=0; j<8; j++) if(I[j] != S[i][j]) sum++;
			gg = min(gg, sum);
		}
		printf("Case %d: %d\n", ++te, gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
