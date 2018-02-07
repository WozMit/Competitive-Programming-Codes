#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	while(cin >> n >> k){
		vector<pair<int, int> > V(n);
		for(int i=0; i<n; i++){
			int aux;
			cin >> aux;
			V[i] = make_pair(aux, i+1);
		}
		sort(V.begin(), V.end());
		vector<int> A;
		int acum = 0;
		for(int i=0; i<n; i++){
			acum+=V[i].first;
			if(acum>k) break;
			A.push_back(V[i].second);
		}
		cout << A.size() <<endl;
		for(int i=0; i<A.size(); i++) cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}