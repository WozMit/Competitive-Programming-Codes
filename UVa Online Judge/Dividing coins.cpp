#include <bits/stdc++.h>
using namespace std;
int n, C[101], DP[1001][50001];

int Knapsack(int pos, int rem){
	if(pos == n || rem == 0) return 0;
	if(DP[pos][rem] != -1) return DP[pos][rem];
	int gg;
	if(C[pos] > rem) gg = Knapsack(pos+1, rem);
	else gg = max(C[pos]+Knapsack(pos+1, rem-C[pos]), Knapsack(pos+1, rem));
	return DP[pos][rem] = gg;
}

int main() {
	std::ios::sync_with_stdio(false);
	int k;
	cin >> k;
	//scanf("%d", &k);
	while(k--){
		cin >> n;
		memset(DP, -1, sizeof DP);
		int total = 0;
		for(int i=0; i<n; i++){
			cin >> C[i];
			//scanf("%d", &C[i]);
			total+=C[i];
		}
		int group1 = Knapsack(0, total/2);
		cout << abs((total-group1)-group1) << endl;
	}
	return 0;
}