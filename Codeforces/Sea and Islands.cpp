#include <bits/stdc++.h>
using namespace std;
char M[101][101];

bool Cond(int i, int j){
	if(j == 0){
		if(i == 0) return false;
		if(M[i-1][0] == 'L') return true;
		return false;
	}
	if(i == 0){
		if(j == 0) return false;
		if(M[0][j-1] == 'L') return true;
		return false;
	}
	if(M[i][j-1] == 'L') return true;
	if(M[i-1][j] == 'L') return true;
	return false;
}

int main() {
	int n, k;
	while(cin >> n >> k){
		if(k>ceil(n*n/2.0)) cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if(k<=0 || Cond(i, j)) M[i][j] = 'S';
					else{
						M[i][j] = 'L';
						k--;
					}
					cout << M[i][j];
				}
				cout << endl;
			}
		}
	}
	return 0;
}