//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
vector<int> G[105], GG;
bool C[105], V[105], Col[105];
int n, e, gg;

void bt(int u){
	if(u == n){
		int sum = 0;
		for(int i=0; i<n; i++) if(C[i]) sum++;
		if(sum > gg){
			gg = sum;
			GG.clear();
			for(int i=0; i<n; i++) if(C[i]) GG.push_back(i);
		}
	}
	else{
		bool flag = true;
		for(int i=0; flag && i<G[u].size(); i++)
			if(Col[G[u][i]] && C[G[u][i]]) flag = false;
		Col[u] = 1;
		if(flag){
			C[u] = 1;
			bt(u+1);
		}
		C[u] = 0;
		bt(u+1);
		Col[u] = 0;
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		int a, b;
		scanf("%d %d", &n, &e);
		while(e--){
			scanf("%d %d", &a, &b);
			a--;b--;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		for(int i=0; i<n; i++) C[i] = V[i] = Col[i] = 0;
		gg = 0;
		bt(0);
		printf("%d\n", gg);
		for(int i=0; i+1<gg; i++) printf("%d ", GG[i]+1);
		if(GG.size()) printf("%d\n", GG[gg-1]+1);
		for(int i=0; i<n; i++) G[i].clear();
		GG.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
