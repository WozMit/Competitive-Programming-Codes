#include <bits/stdc++.h>
using namespace std;

int main() {
	int query, skip;
	while(cin >> query >> skip){
		int actual = 1, counter = 0, l, r;
		while(query--){
			cin >> l >> r; r++;
			actual+=((l-actual)/skip)*skip;
			counter+=r-actual;
			actual = r;
		}
		cout << counter <<endl;
	}
	return 0;
}