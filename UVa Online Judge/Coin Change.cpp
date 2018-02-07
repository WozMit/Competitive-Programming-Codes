#include <bits/stdc++.h>
using namespace std;
int coin[] = {1, 5, 10, 25, 50}, DP[10000];

void Solve(){
	DP[0] = 1;
	for(int i=0; i<5; i++)
		for(int j=coin[i]; j<10000; j++)
			DP[j]+=DP[j-coin[i]];
}

int main() {
	int n;
	Solve();
	while(cin >> n)
		cout << DP[n] << endl;
	return 0;
}