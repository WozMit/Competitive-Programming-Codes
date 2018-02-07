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
typedef long long int ll;
const int MAX = 2005, p = (int)1e9+7;
int dp[MAX][MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, k;
	for(int i=1; i<MAX; i++){
		dp[i][1] = 1;
		for(int m=1; i*m<MAX; m++) dp[i*m][2]++;
	}
	for(int k=2; k<MAX; k++)
		for(int i=1; i<MAX; i++)
			for(int m=1; i*m<MAX; m++) dp[i*m][k+1] = ((ll)dp[i*m][k+1]+(ll)dp[i][k])%p;
	while(scanf("%d %d\n", &n, &k) == 2){
		int gg = 0;
		for(int i=1; i<=n; i++) gg = ((ll)gg+dp[i][k])%p;
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
