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
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int M[20][20], gg = 0;
	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++) scanf("%d", &M[i][j]);
	for(int i=0; i<17; i++)
		for(int j=0; j<17; j++){
			gg = max(gg, M[i][j]*M[i][j+1]*M[i][j+2]*M[i][j+3]);
			gg = max(gg, M[i][j]*M[i+1][j+1]*M[i+2][j+2]*M[i+3][j+3]);
			gg = max(gg, M[i][j]*M[i+1][j]*M[i+2][j]*M[i+3][j]);
		}
	for(int i=0; i<17; i++)
		for(int j=19; j>2; j--)
			gg = max(gg, M[i][j]*M[i+1][j-1]*M[i+2][j-2]*M[i+3][j-3]);
	for(int i=16; i<20; i++)
		for(int j=0; j<17; j++)
			gg = max(gg, M[i][j]*M[i][j+1]*M[i][j+2]*M[i][j+3]);
	printf("%d\n", gg);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
