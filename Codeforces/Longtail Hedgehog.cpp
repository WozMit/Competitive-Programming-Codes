//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
const int MAX_VAL = 100005;
vector<int> G[MAX_VAL];
int dp[MAX_VAL];

int main() {
	int v, e, a, b;
	while(scanf("%d %d", &v, &e) == 2){
		while(e--){
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		ll gg = 0;
		for(int i=1; i<=v; i++){
			dp[i] = 1;
			for(int j=0; j<G[i].size(); j++)
				if(G[i][j] < i) dp[i] = max(dp[i], dp[G[i][j]] + 1);
			gg = max(gg, dp[i]*(ll)G[i].size());
		}
		cout << gg << endl;
		for(int i=1; i<=v; i++) G[i].clear();
	}
	return 0;
}