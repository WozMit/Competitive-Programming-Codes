#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, Ans[11];
	Ans[1] = 1;
	Ans[2] = 2;
	Ans[3] = 6;
	Ans[4] = 20;
	Ans[5] = 70;
	Ans[6] = 252;
	Ans[7] = 924;
	Ans[8] = 3432;
	Ans[9] = 12870;
	Ans[10] = 48620;
	while(cin >> n){
		cout << Ans[n] <<endl;
	}
	return 0;
}