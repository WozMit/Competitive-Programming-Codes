#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 260;
vector<int> G[MAX];
int sol[MAX], n;
bool V[MAX], flag;

void Backtrack(int node, int pos){
	if(pos == n && flag){
		for(int i=0; i<n; i++) printf("%d ", sol[i]);
		printf("1\n");
		flag = false;
	}
	else if(pos == n-1 && flag){
		sol[pos] = node;
		for(int i=0; i<G[node].size(); i++)
			if(G[node][i] == 1) Backtrack(1, pos+1);
	}
	else if(flag){
		V[node] = true;
		sol[pos] = node;
		for(int i=0; i<G[node].size(); i++)
			if(!V[G[node][i]]) Backtrack(G[node][i], pos+1);
		V[node] = false;
	}
}

int main() {
	string s;
	while(scanf("%d", &n) == 1){
		int a, b;
		cin.ignore();
		while(getline(cin, s) && s != "%"){
			sscanf(s.c_str(), "%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		memset(V, false, sizeof V);
		flag = true;
		Backtrack(1, 0);
		if(flag) printf("N\n");
		for(int i=1; i<=n; i++) G[i].clear();
	}
	return 0;
}