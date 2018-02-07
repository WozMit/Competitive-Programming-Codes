//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
const int MAX = 400005;
vector<int> G[MAX];
int n, m, C[MAX], A[MAX], idx, IN[MAX], OUT[MAX], Lazy[4*MAX];
ll ST[4*MAX];
bool V[MAX];

void DFS(int u = 1){
	V[u] = true;
	A[idx] = u;
	IN[u] = idx++;
	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if(!V[v]) DFS(v);
	}
	OUT[u] = idx-1;
}

void Build(int p = 1, int i = 0, int j = n-1){
	Lazy[p] = 0;
	if(i == j) ST[p] = 1ll<<C[A[i]];
	else{
		int m = (i+j)>>1, ln = 2*p, rn = 2*p+1;
		Build(ln, i, m);
		Build(rn, m+1, j);
		ST[p] = ST[ln] | ST[rn];
	}
}

void Refresh(int p, int i, int j){
	if(Lazy[p] != 0ll){
		ST[p] = 0ll;
		ll x = ll(Lazy[p]);
		ST[p] |= 1ll<<x;
		if(i != j){
			Lazy[2*p] = Lazy[p];
			Lazy[2*p+1] = Lazy[p];
		}
		Lazy[p] = 0;
	}
}

void Update(int iq, int jq, int c, int p = 1, int i = 0, int j = n-1){
	Refresh(p, i, j);
	if(i>=iq && j<=jq){
		Lazy[p] = c;
		Refresh(p, i, j);
	}
	else if(!(i > jq || j<iq)){
		int m = (i+j)>>1, ln = 2*p, rn = 2*p+1;
		Update(iq, jq, c, ln, i, m);
		Update(iq, jq, c, rn, m+1, j);
		ST[p] = ST[ln] | ST[rn];
	}
}

ll Query(int iq, int jq, int p = 1, int i = 0, int j = n-1){
	Refresh(p, i, j);
	if(i > jq || j<iq) return 0;
	if(i>=iq && j<=jq) return ST[p];
	int m = (i+j)>>1, ln = 2*p, rn = 2*p+1;
	return (Query(iq, jq, ln, i, m) | Query(iq, jq, rn, m+1, j));
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &m) == 2){
		for(int i=1; i<=n; i++){
			scanf("%d", &C[i]);
			V[i] = false;
		}
		int a, b, c;
		for(int i=1; i<n; i++){
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		idx = 0;
		DFS();
		Build();
		while(m--){
			scanf("%d %d", &a, &b);
			if(a == 1){
				scanf("%d", &c);
				Update(IN[b], OUT[b], c);
			}
			else{
				ll gg = Query(IN[b], OUT[b]);
				printf("%d\n", __builtin_popcountll(gg));
			}
		}
		for(int i=0; i<=n; i++) G[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}