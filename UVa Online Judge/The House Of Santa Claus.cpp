#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
vector<int> G[6];
bool E[6][6];

void Fill(){
	G[1].push_back(2);
	G[1].push_back(3);
	G[1].push_back(5);
	G[2].push_back(1);
	G[2].push_back(3);
	G[2].push_back(5);
	G[3].push_back(1);
	G[3].push_back(2);
	G[3].push_back(4);
	G[3].push_back(5);
	G[4].push_back(3);
	G[4].push_back(5);
	G[5].push_back(1);
	G[5].push_back(2);
	G[5].push_back(3);
	G[5].push_back(4);
}

void DFS(int node, vector<int> V){
	if(V.size() == 8){
		for(int i=0; i<8; i++) printf("%d", V[i]);
		printf("%d\n", node);
	}
	else{
		V.push_back(node);
		for(int i=0; i<G[node].size(); i++){
			if(!(E[node][G[node][i]] || E[G[node][i]][node])){
				E[node][G[node][i]] = E[G[node][i]][node] = true;
				DFS(G[node][i], V);
				E[node][G[node][i]] = E[G[node][i]][node] = false;
			}
		}
	}
}

int main() {
	Fill();
	vector<int> N;
	memset(E, false, sizeof E);
	DFS(1, N);
	return 0;
}