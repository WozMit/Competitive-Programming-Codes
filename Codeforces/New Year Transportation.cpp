#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<vector<int> > G, int node){
	int n = G.size();
	vector<int> D(n, n);
	queue<int> Q;
	D[node] = 0;
	Q.push(node);
	while(!Q.empty()){
		node = Q.front();
		Q.pop();
		for(int i=0; i<G[node].size(); i++){
			if(D[node]+1<D[G[node][i]]){
				D[G[node][i]] = D[node]+1;
				Q.push(G[node][i]);
			}
		}
	}
	return D;
}

int main() {
	int n, t, cell;
	vector<int> D;
	while(cin >> n >> t){
		vector<vector<int> > G(n+1);
		for(int i=1; i<n; i++){
			cin >> cell;
			G[i].push_back(i+cell);
		}
		D = BFS(G, 1);
		cout << (D[t]!=n+1 ? "YES":"NO") <<endl;
	}
	return 0;
}