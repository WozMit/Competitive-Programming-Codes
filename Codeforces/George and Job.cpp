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
const int MAX = 5005;
int A[MAX];
ll S[MAX], dp[MAX][MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, m, k;
	while(scanf("%d %d %d", &n, &m, &k) == 3){
		for(int i=1; i<=n; i++){
			scanf("%d", &A[i]);
			S[i] = A[i] + S[i-1];
		}
		for(int i=1; i<=k; i++)
			for(int j=(i*m); j<=n; j++)
				dp[i][j] = max(dp[i][j-1], dp[i-1][j-m]+S[j]-S[j-m]);
		printf("%I64d\n", dp[k][n]);
	}
	return 0;
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
