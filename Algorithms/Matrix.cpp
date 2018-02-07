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
const int MAX = 100;
struct matrix{
	int M[MAX][MAX], r, c;
	matrix(int pr, int pc){ r = pr, c = pc; }
	matrix I(int k){
		matrix GG = matrix(k, k);
		for(int i=0; i<k; i++) GG.M[i][i] = 1;
		return GG;
	}
	matrix operator +(matrix A)const{
		matrix GG = matrix(r, c);
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++) GG.M[i][j] = M[i][j]+A.M[i][j];
		return GG;
	}
	matrix operator *(matrix A)const{
		matrix GG = matrix(r, A.c);
		for(int i=0; i<r; i++)
			for(int j=0; j<A.c; j++)
				for(int k=0; k<c; k++) GG.M[i][j] += M[i][k]* A.M[k][j];
		return GG;
	}
};

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	matrix T = matrix(6, 4);
	T = T.I(5);
	for(int i=0; i<T.r; i++){
		for(int j=0; j<T.c; j++) cout << T.M[i][j] << " ";
		cout << endl;
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
