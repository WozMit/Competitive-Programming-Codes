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
int n, m, M[MAX][MAX], ix[8], jx[8], even, odd;

void dfs(int x, int y){
	set<pair<int, int> > S;
	for(int k=0; k<8; k++){
		int i = x + ix[k], j = y + jx[k];
		if(i >=0 && i < n && j >= 0 && j < m && M[i][j] != -1) S.insert(make_pair(i, j));
	}
	M[x][y] += S.size();
	if(M[x][y]&1) odd++;
	else even++;
	for(int k=0; k<8; k++){
		int i = x + ix[k], j = y + jx[k];
		if(i >=0 && i < n && j >= 0 && j < m && !M[i][j]) dfs(i, j);
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
		int a, b; scanf("%d %d %d %d", &n, &m, &b, &a);
		ix[0] = -a; ix[1] = -a; ix[2] = -b; ix[3] = b; ix[4] = a; ix[5] = a; ix[6] = b; ix[7] = -b;
		jx[0] = -b; jx[1] = b; jx[2] = a; jx[3] = a; jx[4] = b; jx[5] = -b; jx[6] = -a; jx[7] = -a;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) M[i][j] = 0;
		int w; scanf("%d", &w);
		while(w--){
			scanf("%d %d", &a, &b);
			M[a][b] = -1;
		}
		even = odd = 0;
		dfs(0, 0);
		printf("Case %d: %d %d\n", t+1, even, odd);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
