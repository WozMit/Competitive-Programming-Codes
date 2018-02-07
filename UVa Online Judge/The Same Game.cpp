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
const int n = 10, m = 15;
int M[12][17], ix[] = {-1, 0, 1, 0}, jx[] = {0, 1, 0, -1};
bool V[12][17];

int dfs(int x, int y, bool count = true){
	V[x][y] = true;
	int col = M[x][y];
	if(!count) M[x][y] = -1;
	int gg = 1;
	for(int k=0; k<4; k++){
		int i = x + ix[k], j = y + jx[k];
		if(i>=0 && i<n && j>=0 && j<m && M[i][j] == col && (!V[i][j] || !count))
			gg += dfs(i, j, count);
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	for(int t=0; t<te; t++){
		if(t) printf("\n");
		char s[17];
		for(int i=0; i<n; i++){
			scanf("%s", &s);
			for(int j=0; j<m; j++) M[i][j] = (s[j] == 'R' ? 0:(s[j] == 'G' ? 1:2));
		}
		int score = 0, remain = 150, move = 0;
		printf("Game %d:\n\n", t+1);
		while(true){
			memset(V, false, sizeof V);
			int balls = 0, ipos, jpos;
			for(int j=0; j<m; j++)
				for(int i=n-1; i>=0; i--)
					if(!V[i][j] && M[i][j] != -1){
						int count = dfs(i, j);
						if(count > balls) balls = count, ipos = i, jpos = j;
					}
			if(balls > 1){
				char color = (!M[ipos][jpos] ? 'R':(M[ipos][jpos] == 1 ? 'G':'B'));
				int get = (balls-2)*(balls-2);
				score += get;
				remain -= balls;
				if(!remain) score += 1000;
				dfs(ipos, jpos, false);
				for(int j=0; j<m; j++)
					for(int i=n-2; i>=0; i--){
						int pos = i;
						while(pos+1 < n && M[pos+1][j] == -1) pos++;
						if(pos != i) swap(M[i][j], M[pos][j]);
					}
				for(int j=1; j<m; j++){
					int pos = j;
					while(pos-1>=0 && M[n-1][pos-1] == -1) pos--;
					if(pos != j) for(int i=0; i<n; i++) swap(M[i][j], M[i][pos]);
				}
				printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", ++move, 10-ipos, jpos+1, balls, color, get);
			} else break;
		}
		printf("Final score: %d, with %d balls remaining.\n", score, remain);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
