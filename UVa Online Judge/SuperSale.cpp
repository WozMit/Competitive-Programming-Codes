#include <bits/stdc++.h>
using namespace std;
const int MAX = 1002;
int n, V[MAX][2], DP[MAX][32];

int Knapsack(int pos, int rem){
	if(pos == n || rem == 0) return 0;
	if(DP[pos][rem] != -1) return DP[pos][rem];
	int ans;
	if(V[pos][0] <= rem) ans = max(Knapsack(pos+1, rem), V[pos][1]+Knapsack(pos+1, rem-V[pos][0]));
	else ans = Knapsack(pos+1, rem);
	return DP[pos][rem] = ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &V[i][1]); scanf("%d", &V[i][0]);
		}
		int g, total, gg = 0;
		scanf("%d", &g);
		while(g--){
			memset(DP, -1, sizeof DP);
			scanf("%d", &total);
			gg+=Knapsack(0, total);
		}
		cout << gg << endl;
	}
	return 0;
}