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
char M[MAX][MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, m, te = 0;
	while(scanf("%d %d", &n, &m) == 2 && (n || m)){
		if(te) printf("\n");
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) scanf(" %c", &M[i][j]);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(M[i][j] != '*'){
					int cont = 0;
					if(i-1>=0 && j-1>=0 && M[i-1][j-1] == '*') cont++;
					if(i-1>=0 && M[i-1][j] == '*') cont++;
					if(i-1>=0 && j+1<m && M[i-1][j+1] == '*') cont++;
					if(j-1>=0 && M[i][j-1] == '*') cont++;
					if(j+1 < m && M[i][j+1] == '*') cont++;
					if(i+1 < n && j-1>=0 && M[i+1][j-1] == '*') cont++;
					if(i+1 < n && M[i+1][j] == '*') cont++;
					if(i+1 < n && j+1 < m && M[i+1][j+1] == '*') cont++;
					M[i][j] = (cont+'0');
				}
		printf("Field #%d:\n", ++te);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++) printf("%c", M[i][j]);
			printf("\n");
		}
	}
	#ifdef WozMit
		//printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
