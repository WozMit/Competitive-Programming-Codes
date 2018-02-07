#include <bits/stdc++.h>
using namespace std;
int Suit[25], DP[25][201], n, total;

void Build(string s){
	stringstream stream(s);
	total = n = 0;
	while(1){
		int k;
		stream >> k;
		if(!stream) break;
		Suit[n++] = k;
		total+=k;
	}
}

int Knapsack(int pos, int rem){
	if(pos == n || rem == 0) return 0;
	if(DP[pos][rem] != -1) return DP[pos][rem];
	int ans;
	if(Suit[pos] <= rem) ans = max(Knapsack(pos+1, rem), Suit[pos]+Knapsack(pos+1, rem-Suit[pos]));
	else ans = Knapsack(pos+1, rem);
	return DP[pos][rem] = ans;
}

int main() {
	int t;
	string s;
	scanf("%d", &t);
	getline(cin, s);
	while(t--){
		getline(cin, s);
		Build(s);
		memset(DP, -1, sizeof DP);
		if(total&1 || Knapsack(0, total/2) != total/2) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}