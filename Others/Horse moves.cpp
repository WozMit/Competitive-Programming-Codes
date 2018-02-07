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
int ix[] = {-2, -1, 1, 2, 2, 1, -1, -2}, jx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int M[10][10];

void Colocar(int x, int y, int numero){
	M[x][y] = numero;
	for(int k=0; k<8; k++){
		int i = x + ix[k], j = y + jx[k];
		if(numero < 64 && i>=0 && i<8 && j>=0 && j<8 && M[i][j] == -1)
			Colocar(i, j, numero + 1);
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++) M[i][j] = -1;
	Colocar(0, 0, 1);
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++) cout << M[i][j] << " ";
		cout << endl;
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
