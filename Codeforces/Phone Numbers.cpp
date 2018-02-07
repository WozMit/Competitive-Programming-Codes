//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;

bool pref(string s, string t){
	if(s.size() > t.size()) return false;
	for(int i=0; i<s.size(); i++)
		if(s[i] != t[i]) return false;
	return true;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		map<string, vector<string> > M;
		while(n--){
			string s, t; int x;
			cin >> s; scanf("%d", &x);
			while(x--){ cin >> t; M[s].push_back(t); }
		}
		printf("%d\n", M.size());
		for(map<string, vector<string> >::iterator i=M.begin(); i!=M.end(); i++){
			vector<string> V = (*i).second, G;
			for(int j=0; j<V.size(); j++) reverse(V[j].begin(), V[j].end());
			sort(V.begin(), V.end());
			for(int j=0; j<V.size()-1; j++)
				if(!pref(V[j], V[j+1])) G.push_back(V[j]);
			G.push_back(V[V.size() - 1]);
			for(int j=0; j<G.size(); j++) reverse(G[j].begin(), G[j].end());
			printf("%s %d", (*i).first.c_str(), G.size());
			for(int j=0; j<G.size(); j++) printf(" %s", G[j].c_str());
			printf("\n");
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
