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
const int MAX = (int)1e6+5, p = (int)1e9+7;
int A[MAX], dp[MAX];
vector<int> D[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		int maxi = 0;
		for(int i=0; i<n; i++) maxi = max(maxi, A[i]);
		for(int i=1; i*i<=maxi; i++)
			for(int j=i*i; j<=maxi; j+=i)
				D[j].push_back(i);
		dp[0] = 1;
		for(int j=1; j<=n; j++) dp[j] = 0;
		for(int i=0; i<n; i++){
			set<int> S(D[ A[i] ].begin(), D[ A[i] ].end());
			for(int e : D[ A[i] ]) S.insert(A[i] / e);
			for(int e : S){
				int j = A[i] / e;
				dp[j] = (dp[j] + dp[j - 1])%p;
			}
		}
		int gg = 0;
		for(int i=1; i<=n; i++) gg = (gg + dp[i])%p;
		printf("%d\n", gg);
		for(int i=0; i<=maxi; i++) D[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
