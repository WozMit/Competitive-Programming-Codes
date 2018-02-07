#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, s;
	while(cin >> n >> s){
		map<int, int> A, B;
		char x;
		int y, z;
		for(int i=0; i<n; i++){
			cin >> x >> y >> z;
			if(x == 'S'){
				if(A.count(y)) A[y] += z;
				else A[y] = z;
			}
			else{
				if(B.count(y)) B[y] += z;
				else B[y] = z;
			}
		}
		vector<pair<int, int> > V1(A.rbegin(), A.rend());
		vector<pair<int, int> > V2(B.rbegin(), B.rend());
		for(int i=0; i<V1.size() && i<s; i++)
			cout << "S " << V1[i].first << " " << V1[i].second << endl;
		for(int i=0; i<V2.size() && i<s; i++)
			cout << "B " << V2[i].first << " " << V2[i].second << endl;
	}
	return 0;
}