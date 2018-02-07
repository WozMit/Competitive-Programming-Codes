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
const int MAX = 205;
int M[MAX][MAX], n, m, ix[] = {-1, 0, 1, 0}, jx[] = {0, 1, 0, -1}, holes;
char h[] = "WAKJSD";

void dfs(int x, int y){
	int color = M[x][y];
	M[x][y] = -1;
	for(int k=0; k<4; k++){
		int i = x + ix[k], j = y + jx[k];
		if(i < 0 || i >= n || j < 0 || j >= m) continue;
		if(M[i][j] == color) dfs(i, j);
		else if(color == 1 && !M[i][j]){
			holes++;
			dfs(i, j);
		}
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te = 0;
	while(scanf("%d %d", &n, &m) && n+m){
		char s[52];
		for(int i=0; i<n; i++){
			scanf("%s", &s);
			for(int j=0; j<m; j++){
				int numb = isdigit(s[j]) ? (s[j] - '0'):(s[j] - 'a' + 10);
				for(int k=0; k<4; k++) M[i][4*j+3-k] = 1&(numb>>k);
			}
		}
		m *= 4;
		for(int i=0; i<n; i++){
			if(!M[i][0]) dfs(i, 0);
			if(!M[i][m-1]) dfs(i, m-1);
		}
		for(int j=0; j<m; j++){
			if(!M[0][j]) dfs(0, j);
			if(!M[n-1][j]) dfs(n-1, j);
		}
		string gg = "";
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(M[i][j] == 1){
					holes = 0;
					dfs(i, j);
					gg += h[holes];
				}
		sort(gg.begin(), gg.end());
		printf("Case %d: %s\n", ++te, gg.c_str());
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
