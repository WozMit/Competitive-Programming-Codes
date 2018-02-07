#include <bits/stdc++.h>
using namespace std;
int DP[1001][1001];

int main() {
	string s1, s2;
	while(getline(cin, s1)){
		getline(cin, s2);
		int n = s1.size(), m = s2.size();
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++){
				if(s1[i-1] == s2[j-1]) DP[i][j] = DP[i-1][j-1]+1;
				else DP[i][j] = max(DP[i][j-1], DP[i-1][j]);
			}
		cout << DP[n][m] << endl;
	}
	return 0;
}