#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;
int S[10005];

int Sum(int i, int j){
	if(j<i) return -inf;
	return S[j]-(i==0 ? 0:S[i-1]);
}

int main() {
	int t, n, x1, y1, x2, y2;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> S[i];
			S[i] += i != 0 ? S[i-1]:0;
		}
		cin >> n;
		while(n--){
			cin >> x1 >> y1 >> x2 >> y2;
			int max = -inf;
			for(int i=x1-1; i<=y1-1; i++)
				for(int j=x2-1; j<=y2-1; j++)
					if(Sum(i, j) > max) max = Sum(i, j);
			cout << max << endl;
		}
	}
	return 0;
}