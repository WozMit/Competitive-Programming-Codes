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
int A[10000005][2];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int r[] = {0, 1, 1, -1}, c[] = {1, -1, 0, 1};
	int i = 0, j = 0, dir = -1, cont = 1, n;
	A[0][0] = A[0][1] = 1;
	while(cont < 10000002){
		cont++;
		if(dir == -1) dir = 0;
		else if(!dir) dir = !i ? 1:3;
		else if(dir == 2) dir = !j ? 3:1;
		else if(dir == 1 && !j) dir = 2;
		else if(dir == 3 && !i) dir = 0;
		i += r[dir];
		j += c[dir];
		A[cont-1][0] = i+1, A[cont-1][1] = j+1;
	}
	while(scanf("%d", &n) == 1) printf("TERM %d IS %d/%d\n", n, A[n-1][0], A[n-1][1]);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
