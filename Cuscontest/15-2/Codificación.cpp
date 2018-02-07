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

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t;
	scanf("%d", &t);
	char M[103][103];
	int r[] = {0, 1, 1, -1}, c[] = {1, -1, 0, 1};
	while(t--){
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) scanf(" %c", &M[i][j]);
		string gg = "";
		int i = 0, j = 0, dir = -1;
		while(i != n-1 || j != m-1){
			gg += M[i][j];
			if(dir == -1) dir = (j == m-1) ? 2:0;
			else if(!dir) dir = !i ? 1:3;
			else if(dir == 2) dir = !j ? 3:1;
			else if(dir == 1){
				if(!j) dir = i == n-1 ? 0:2;
				else if(i == n-1) dir = 0;
			}
			else if(dir == 3){
				if(!i) dir = j == m-1 ? 2:0;
				else if(j == m-1) dir = 2;
			}
			i += r[dir];
			j += c[dir];
		}
		gg += M[n-1][m-1];
		printf("%s\n", gg.c_str());
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
