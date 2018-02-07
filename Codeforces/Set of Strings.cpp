#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	string q;
	while(cin >> k >> q){
		bool flag = true;
		if(k > q.size()) flag = false;
		vector<string> V;
		set<char> S;
		int count = 0;
		for(int i=0; i<q.size() && flag; i++){
			int j;
			S.insert(q[i]);
			for(j = i+(i == q.size()-1 ? 0:1); j<q.size(); j++)
				if(!S.count(q[j])) break;
			if(count == k-1){
				V.push_back(q.substr(i, q.size()-i+1));
				break;
			}
			else
				V.push_back(q.substr(i, j-i));
			count++;
			i = j-1;
		}
		if(V.size() < k) flag = false;
		if(!flag) cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			for(int i=0; i<V.size(); i++)
				cout << V[i] << endl;
		}
	}
	return 0;
}