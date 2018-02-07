#include <bits/stdc++.h>
using namespace std;
int n = 15, M[16][16], memo[16][16];

int SolveIt(int i, int j){
	if(i == n-1) return memo[i][j] = M[i][j];
	if(memo[i][j] != -1) return memo[i][j];
	int gg = M[i][j] + max(SolveIt(i+1, j), SolveIt(i+1, j+1));
	return memo[i][j] = gg;
}

int main() {
	for(int i=0; i<n; i++)
		for(int j=0; j<i+1; j++) cin >> M[i][j];
	memset(memo, -1, sizeof memo);
	cout << SolveIt(0, 0) << endl;
	return 0;
}