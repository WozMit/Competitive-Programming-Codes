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
const int MAX = 23;
int M[MAX][MAX], n, m, ix[] = {-1, 0, 1, 0}, jx[] = {0, 1, 0, -1};

int dfs(int x, int y){
	int color = M[x][y], gg = 1;
	M[x][y] = -1;
	for(int k=0; k<4; k++){
		int i = x + ix[k], j = (y + jx[k] + m)%m;
		if(i < 0 || i >= n) continue;
		if(M[i][j] == color) gg += dfs(i, j);
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &m) == 2){
		char s[MAX], c1;
		for(int i=0; i<n; i++){
			scanf("%s", &s);
			if(!i) c1 = s[0];
			for(int j=0; j<m; j++) M[i][j] = (s[j] == c1);
		}
		int x, y; scanf("%d %d", &x, &y);
		int color = M[x][y], gg = 0;
		dfs(x, y);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(M[i][j] == color) gg = max(gg, dfs(i, j));
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
