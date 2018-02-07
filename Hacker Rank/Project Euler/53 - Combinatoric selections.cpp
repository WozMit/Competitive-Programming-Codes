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
typedef long long int ll;
const int MAX = (int)1e3+5;
ll C[MAX][MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	ll k;
	while(scanf("%d %lld", &n, &k) == 2){
		for(int i=0; i<=n; i++) C[i][0] = C[i][i] = 1ll;
		int gg = 0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<i; j++){
				ll val = C[i-1][j-1] + C[i-1][j];
				if(val > k){
					val = k + 1, gg++;
				}
				C[i][j] = val;
			}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
