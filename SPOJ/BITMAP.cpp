//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
#define fi first
#define se second
using namespace std;
const int MAX = 185, oo = 1<<30;
char M[MAX][MAX];
int n, m, d[MAX][MAX], ix[] = {-1, 0, 1, 0}, jx[] = {0, 1, 0, -1};
queue<pair<int, int> > Q;

void bfs(){
	pair<int, int> u;
	while(!Q.empty()){
		u = Q.front(); Q.pop();
		for(int k=0; k<4; k++){
			int i = u.fi + ix[k], j = u.se + jx[k];
			if(i >= 0 && i <n && j >=0 && j < m && d[u.fi][u.se] + 1 < d[i][j]){
				d[i][j] = d[u.fi][u.se] + 1;
				Q.push(make_pair(i, j));
			}
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
	while(te--){
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++) scanf("%s", &M[i]);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){
				d[i][j] = oo;
				if(M[i][j] == '1'){
					d[i][j] = 0;
					Q.push(make_pair(i, j));
				}
			}
		bfs();
		for(int i=0; i<n; i++){
			for(int j=0; j<m-1; j++) printf("%d ", d[i][j]);
			printf("%d\n", d[i][m-1]);
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
