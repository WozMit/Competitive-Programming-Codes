//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = (int)1e5+5;
vector<int> H[MAX];
int M[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, m;
	while(scanf("%d %d", &n, &m) == 2){
		for(int i=0; i<m; i++) M[i] = -1;
		int k = 0;
		for(int i=0; i<n; i++){
			int x, y; scanf("%d %d", &x, &y);
			x--;
			if(M[x] == -1) M[x] = k++;
			H[ M[x] ].push_back(y);
		}
		int maxj = 0, gg = 0;
		for(int i=0; i<k; i++){
			sort(H[i].rbegin(), H[i].rend());
			maxj = max(maxj, (int)H[i].size());
			for(int j=1; j<H[i].size(); j++)
				H[i][j] += H[i][j - 1];
		}
		for(int j=0; j<maxj; j++){
			int sum = 0;
			for(int i=0; i<k; i++)
				if(H[i].size() >= j + 1 && H[i][j] > 0) sum += H[i][j];
			gg = max(gg, sum);
		}
		printf("%d\n", gg);
		for(int i=0; i<k; i++) H[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
