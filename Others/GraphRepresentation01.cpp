//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int point[11], last[11], nxt[11];
bool V[10];

void DFS(int u){
	V[u] = true;
	cout << u << " ";
	for(int i=last[u]; i!=-1; i=nxt[i]){
		int v = point[i];
		if(!V[v]) DFS(v);
	}
}

int main() {
	int v, e;
	while(scanf("%d %d", &v, &e) == 2){
		memset(last, -1, sizeof last);
		memset(nxt, -1, sizeof nxt);
		int a, b, k = 1;
		while(e--){
			scanf("%d %d", &a, &b);
			point[k] = b;
			nxt[k] = last[a];
			last[a] = k++;
		}
		for(int i=1; i<=5; i++) cout << "point[" << i << "] = " << point[i] << endl;
		for(int i=1; i<=5; i++) cout << "last[" << i << "] = " << last[i] << endl;
		for(int i=1; i<=5; i++) cout << "nxt[" << i << "] = " << nxt[i] << endl;
		int u = 2;
		for(int i = last[u]; i!=-1; i=nxt[i]){ //for all adj(u)
			int v = point[i];
			cout << v << " ";
		}
		cout << endl;
		memset(V, false, sizeof V);
		DFS(1);
	}
	return 0;
}

/*INPUT:
5 5

1 2
1 3
3 4
2 5
2 4
*/