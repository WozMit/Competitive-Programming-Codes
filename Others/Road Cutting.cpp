#include <bits/stdc++.h>
using namespace std;
int P[50], DP[50];

int Sol(int len){
	if(len == 1) return P[1];
	if(DP[len] != -1) return DP[len];
	int gg = P[len];
	for(int i=1; i<len; i++)
		gg = max(gg, P[i]+Sol(len-i));
	return DP[len] = gg;
}

int main() {
	int n;
	while(cin >> n){
		memset(DP, -1, sizeof DP);
		for(int i=1; i<=n; i++) cin >> P[i];
		cout << Sol(50) << endl;
	}
	return 0;
}