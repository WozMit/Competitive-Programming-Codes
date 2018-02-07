#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	while(cin >> n >> m >> k){
		vector<int> I(m+2, 0);
		vector<vector<int> > M(n+2, I);
		int ans = 0, x, y;
		bool flag = true, c1, c2, c3, c4;
		for(int i=1; i<=k; i++){
			cin >> x >> y;
			M[x][y] = 1;
			c1 = M[x][y-1] && M[x-1][y-1] && M[x-1][y];
			c2 = M[x-1][y] && M[x-1][y+1] && M[x][y+1];
			c3 = M[x][y+1] && M[x+1][y+1] && M[x+1][y];
			c4 = M[x][y-1] && M[x+1][y-1] && M[x+1][y];
			if(flag && (c1 || c2 || c3 || c4)){
				ans = i;
				flag = false;
			}
		}
		cout << ans <<endl;
	}
	return 0;
}