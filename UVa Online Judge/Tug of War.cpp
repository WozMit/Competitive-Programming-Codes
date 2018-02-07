#include <bits/stdc++.h>
using namespace std;
int n, W[101], DP[101][45001];

int Solve(int pos, int rem){
	if(pos == n || rem == 0) return 0;
	if(DP[pos][rem] != -1) return DP[pos][rem];
	int ans;
	if(W[pos] > rem) ans = Solve(pos+1, rem);
	else ans = max(Solve(pos+1, rem), W[pos]+Solve(pos+1, rem-W[pos]));
	return DP[pos][rem] = ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int total = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &W[i]);
			total+=W[i];
		}
		n/=2;
		memset(DP, -1, sizeof DP);
		int g1 = Solve(0, total);
		int min = g1 < total-g1 ? g1:total-g1, max = total-min;
		cout << min << " " << max << endl;
	}
	return 0;
}