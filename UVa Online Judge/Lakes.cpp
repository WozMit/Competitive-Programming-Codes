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
const int MAX = 105;
int n, m, M[MAX][MAX], gg;
int ix[] = {-1, 0, 1, 0}, jx[] = {0, 1, 0, -1};

void dfs(int x, int y){
	M[x][y] = -1;
	gg++;
	for(int k=0; k<4; k++){
		int i = x + ix[k], j = y + jx[k];
		if(i >=0 && i < n && j >= 0 && j < m && M[i][j] == 0) dfs(i, j);
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	bool flag = false;
	while(te--){
		if(flag) printf("\n");
		else flag = true;
		int x, y; scanf("%d %d", &x, &y);
		x--; y--;
		string s = " ";
		cin.ignore();
		n = 0;
		while(getline(cin, s) && s != ""){
			if(!n) m = s.size();
			for(int i=0; i<m; i++) M[n][i] = (s[i] == '1');
			n++;
		}
		gg = 0;
		dfs(x, y);
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
