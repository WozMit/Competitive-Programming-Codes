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
char M[103][103];
int im[] = {-1, 0, 1, 0}, jm[] = {0, 1, 0, -1};

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, m, s;
	while(scanf("%d %d %d", &n, &m, &s) == 3 && !(!n && !m && !s)){
		char q[s], c;
		int x, y, k, gg = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){
				scanf(" %c", &c);
				M[i][j] = c;
				if(c == 'N') k = 0, x = i, y = j;
				else if(c == 'S') k = 2, x = i, y = j;
				else if(c == 'L') k = 1, x = i, y = j;
				else if(c == 'O') k = 3, x = i, y = j;
			}
		scanf("%s", &q);
		for(int i=0; i<s; i++){
			if(q[i] == 'F'){
				int xt = x + im[k], yt = y + jm[k];
				if(!(xt < 0 || xt == n || yt < 0 || yt == m || M[xt][yt] == '#'))
					x = xt, y = yt;
			}
			else k = q[i] == 'D' ? (k+1)%4:(k+3)%4;
			if(M[x][y] == '*') gg++, M[x][y] = '.';
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
