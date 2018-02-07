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
const int MAX = 50;
char s[MAX], word[MAX], A[MAX];
int n, in_deg[MAX];
bool V[MAX];
map<char, int> M;
vector<int> G[MAX], solution;
vector<string> gg;

void bt(){
	if(solution.size() == n){
		string s = "";
		for(int i=0; i<n; i++){
			s += A[ solution[i] ];
			if(i < n-1) s += " ";
		}
		gg.push_back(s);
	} else
	for(int u=0; u<n; u++){
		if(V[u] || in_deg[u]) continue;
		V[u] = true;
		solution.push_back(u);
		for(int i=0; i<G[u].size(); i++) in_deg[ G[u][i] ]--;
		bt();
		for(int i=0; i<G[u].size(); i++) in_deg[ G[u][i] ]++;
		V[u] = false;
		solution.pop_back();
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	bool flag = false;
	while(te--){
		if(!flag) flag = true;
		else printf("\n");
		scanf(" %[^\n]", s);
		while(int(s[0]) == 0) scanf(" %[^\n]", s);
		n = 0;
		int add;
		for (char *t = s; sscanf(t, "%s%n", word, &add) == 1; t += add){
			M[ word[0] ] = n;
			A[n++] = word[0];
		}
		for(int i=0; i<n; i++) in_deg[i] = V[i] = 0;
		scanf(" %[^\n]", s);
		for (char *t = s; sscanf(t, "%s%n", word, &add) == 1; t += add){
			int u = M[ word[0] ], v = M[ word[2] ];
			if(word[1] == '<') G[u].push_back(v), in_deg[v]++;
			else G[v].push_back(u), in_deg[u]++;
		}
		bt();
		sort(gg.begin(), gg.end());
		if((int)gg.size())
			for(int i=0; i<gg.size(); i++) printf("%s\n", gg[i].c_str());
		else puts("NO");
		for(int i=0; i<n; i++) G[i].clear();
		M.clear();
		gg.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
