#include <bits/stdc++.h>
using namespace std;
const int MAX_VAL = 2000;
int v, idx;
bool G[MAX_VAL][MAX_VAL], V[MAX_VAL];
vector<pair<int, int> > S;

void DFS(int node, bool f){
	V[node] = true;
	if(f) idx++;
	for(int i=0; i<v; i++)
		if(G[node][i] && !V[i]) DFS(i, f);
	if(f) S.push_back(make_pair(idx++, node));
}

bool Tarjan(){
	memset(V, false, sizeof V);
	idx = 0;
	for(int i=0; i<v; i++)
		if(!V[i]) DFS(i, true);
	sort(S.rbegin(), S.rend());
	for(int i=0; i<v; i++)
		for(int j=i+1; j<v; j++) swap(G[i][j], G[j][i]);
	memset(V, false, sizeof V);
	for(int i=0; i<S.size(); i++)
		if(!V[S[i].second]){
			if(i) return false;
			DFS(S[i].second, false);
		}
	return true;
}

int main() {
	while(scanf("%d", &v) == 1){
		int x;
		for(int i=0; i<v; i++)
			for(int j=0; j<v; j++){
				scanf("%d", &x);
				G[i][j] = x ? true:false;
			}
		if(Tarjan()) printf("YES\n");
		else printf("NO\n");
		S.clear();
	}
	return 0;
}