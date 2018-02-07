#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int A[1000];

int main() {
	int n;
	while(scanf("%d", &n) == 1){
		vector<pair<string, int> > V;
		map<string, int> M;
		int pt, gg = 0;
		string name;
		while(n--){
			cin >> name >> pt;
			if(M.count(name)) M[name] += pt;
			else M[name] = pt;
			V.push_back(make_pair(name, pt));
			gg = max(gg, M[name]);
		}
		for(int i=0; i<V.size(); i++) cout << V[i].first << " " << V[i].second << endl;
		cout << gg << endl;
		/*for(int i=0; i<V.size(); i++)
			if(V[i].second > gg){
				cout << V[i].first << endl;
				break;
			}*/
	}
	return 0;
}