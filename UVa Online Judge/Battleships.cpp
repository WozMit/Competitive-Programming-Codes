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
const int MAX = 102;
int M[MAX][MAX], n, gg, ix[] = {-1, 0, 1, 0}, jx[] = {0, 1, 0, -1};
bool check;

void dfs(int x, int y){
	M[x][y] = -1;
	for(int k=0; k<4; k++){
		int i = x + ix[k], j = y + jx[k];
		if(i >= 0 && i < n && j >= 0 && j < n && M[i][j] > 0){
			if(M[i][j] == 1 && check) check = false, gg++;
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
	int te; scanf("%d", &te);
	for(int t=0; t<te; t++){
		scanf("%d", &n);
		char s[MAX];
		for(int i=0; i<n; i++){
			scanf("%s", &s);
			for(int j=0; j<n; j++) M[i][j] = s[j] == '.' ? 0:(s[j] == 'x' ? 1:2);
		}
		gg = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				if(M[i][j] == 1){
					check = false;
					gg++;
					dfs(i, j);
				}
				else if(M[i][j] == 2){
					check = true;
					dfs(i, j);
				}
			}
		printf("Case %d: %d\n", t+1, gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
