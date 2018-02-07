#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, x;
	set<int> S;
	cin >> t;
	while(t--){
		for(int i=0; i<4; i++){
			cin >> x;
			S.insert(x);
		}
		if(S.size() == 1) cout << "square" << endl;
		else if(S.size() == 2) cout << "rectangle" << endl;
		else if()
	}
	return 0;
}