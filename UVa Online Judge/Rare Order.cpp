//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <stack>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = 30;
vector<int> G[MAX];
stack<int> S;
bool Visit[MAX];

int dfs(int u){
	Visit[u] = 1;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(!Visit[v]) dfs(v);
	}
	S.push(u);
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	string s;
	vector<string> V;
	int n = 0;
	while(cin >> s && s != "#") V.push_back(s), n++;
	string a, b;
	vector<int> Nodes;
	for(int i=1; i<n; i++){
		string a = V[i-1], b = V[i];
		int idx = 0;
		while(idx < a.size() && idx < b.size() && a[idx] == b[idx]) idx++;
		if(idx < a.size() && idx < b.size()){
			Nodes.push_back(a[idx]-65);
			if(i == n-1) Nodes.push_back(b[idx]-65);
			G[(a[idx]-65)].push_back((b[idx]-65));
		}
	}
	memset(Visit, 0, sizeof Visit);
	for(int i=0; i<Nodes.size(); i++)
		if(!Visit[Nodes[i]]) dfs(Nodes[i]);
	string gg = "";
	while(!S.empty()){
		int x = S.top();
		S.pop();
		gg += x + 65;
	}
	printf("%s\n", gg.c_str());
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
