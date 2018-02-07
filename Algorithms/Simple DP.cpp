#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000;

int M[MAX][MAX], DP[MAX][MAX];

int S(int a, int b){
	//if(DP[a][b] != -1) return DP[a][b];
	if(a < 0 || b < 0) return 0;
	return M[a][b]+S(a, b-1)+S(a-1, b)-S(a-1, b-1);
	//return DP[a][b] = M[a][b]+S(a, b-1)+S(a-1, b)-S(a-1, b-1);
}

int Sum(int a, int b, int c, int d){
	return S(c, d)-S(c, b-1)-S(a-1, d)+S(a-1, b-1);
}

int main() {
	int n;
	while(cin >> n){
		memset(DP, -1, sizeof DP);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) cin >> M[i][j];
		cout << Sum(0, 0, 99, 99) << endl;
	}
	return 0;
}