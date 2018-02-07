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
#define fi first
#define se second
int n, m;
pair<int, int> A[17], a, b;
bool gg, V[17];

void bt(int last, int pieces){
	for(int i=0; i<m; i++)
		if(!V[i] && A[i].fi == A[last].se){
			if(pieces+1 == n && A[i].se == b.fi) gg = true;
			else{
				V[i] = true;
				bt(i, pieces+1);
				V[i] = false;
			}
		}
		else if(!V[i] && A[i].se == A[last].se){
			swap(A[i].fi, A[i].se);
			if(pieces+1 == n && A[i].se == b.fi) gg = true;
			else{
				V[i] = true;
				bt(i, pieces+1);
				V[i] = false;
			}
			swap(A[i].fi, A[i].se);
		}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d", &n) == 1 && n){
		scanf("%d", &m);
		scanf("%d %d %d %d", &a.fi, &a.se, &b.fi, &b.se);
		for(int i=0; i<m; i++) scanf("%d %d", &A[i].fi, &A[i].se);
		gg = false;
		memset(V, 0, sizeof V);
		for(int i=0; i<m; i++)
			if(A[i].fi == a.se){
				V[i] = true;
				bt(0, 1);
				V[i] = false;
			}
			else if(A[i].se == a.se){
				swap(A[i].fi, A[i].se);
				V[i] = true;
				bt(0, 1);
				V[i] = false;
				swap(A[i].fi, A[i].se);
			}
		if(!gg) printf("NO\n");
		else printf("YES\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
