#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 20005;
struct Node{
	int v, w;
	Node(int pv, int pw){ v =pv; w = pw; }
	bool operator <(Node a)const{ return w>a.w; }
};
bool V[MAX];
vector<Node> G[MAX];
priority_queue<Node> Q;
int n, e, st, end, D[MAX];

void Dijkstra(){
	for(int i=0; i<n; i++){
		V[i] = false;
		D[i] = 1<<30;
	}
	D[st] = 0;
	Q.push(Node(st, 0));
	while(!Q.empty()){
		Node p = Q.top();
		Q.pop();
		V[p.v] = true;
		for(int i=0; i<G[p.v].size(); i++){
			int adjv = G[p.v][i].v, adjw = G[p.v][i].w;
			if(!V[adjv] && D[p.v]+adjw < D[adjv]){
				D[adjv] = D[p.v]+adjw;
				Q.push(Node(adjv, D[adjv]));
			}
		}
	}
}

int main() {
	int t, a, b, w;
	scanf("%d", &t);
	for(int tf=1; tf<=t; tf++){
		scanf("%d %d %d %d", &n, &e, &st, &end);
		while(e--){
			scanf("%d %d %d", &a, &b, &w);
			G[a].push_back(Node(b, w));
			G[b].push_back(Node(a, w));
		}
		Dijkstra();
		if(D[end] < 1<<30) printf("Case #%d: %d\n", tf, D[end]);
		else printf("Case #%d: unreachable\n", tf);
		for(int i=0; i<n; i++) G[i].clear();
	}
	return 0;
}