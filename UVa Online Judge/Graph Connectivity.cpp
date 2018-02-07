//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n"
using namespace std;
vector<int> G[30];
bool V[30];

void dfs(int u){
	V[u] = 1;
	for(int i=0; i<G[u].size(); i++)
		if(!V[G[u][i]]) dfs(G[u][i]);
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te, v;
	char c1, c2;
	string s;
	scanf("%d", &te);
	for(int k=0; k<te; k++){
		if(k) printf("\n");
		scanf(" %c", &c1);
		v = c1-64;
		cin.ignore();
		getline(cin, s);
		while(s != ""){
			sscanf(s.c_str()," %c%c", &c1, &c2);
			G[c1-65].push_back(c2-65);
			G[c2-65].push_back(c1-65);
			getline(cin, s);
		}
		memset(V, 0, sizeof V);
		int gg = 0;
		for(int i=0; i<v; i++)
			if(!V[i]){
				dfs(i);
				gg++;
			}
		printf("%d\n", gg);
		for(int i=0; i<v; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
