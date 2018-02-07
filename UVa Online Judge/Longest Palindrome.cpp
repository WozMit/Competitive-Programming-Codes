#include <bits/stdc++.h>
using namespace std;
int DP[1003][1003], n;
string s, r;

void Solve(){
	n = s.size();
	r = s;
	reverse(r.begin(), r.end());
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			if(r[i-1] == s[j-1]) DP[i][j] = DP[i-1][j-1]+1;
			else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
		}
}

int main() {
	int t;
	scanf("%d", &t);
	cin.ignore();
	while(t--){
		getline(cin, s);
		Solve();
		printf("%d\n", DP[n][n]);
	}
	return 0;
}