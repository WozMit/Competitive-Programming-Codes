//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = (int)2e3+5;
int A[MAX], paired[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=2*n; i++) scanf("%d", &A[i]);
	set<pair<int, int> > P;
	for(int i=0; i<=2*n; i++) paired[i] = -1;
	while(m--){
		int x, y; scanf("%d %d", &x, &y);
		paired[x] = y;
		paired[y] = x;
		P.insert(make_pair(min(x, y), max(x, y)));
	}
	vector<pair<int, int> > V(2*n);
	for(int i=0; i<2*n; i++) V[i] = make_pair(A[i + 1], i + 1);
	sort(V.rbegin(), V.rend());
	int turn; scanf("%d", &turn);
	turn--;
	int last = 0, byHim = -1;
	for(int k=0; k<2*n; k++, turn = 1 - turn){
		if(turn == 0){ // Me
			int idx;
			if(byHim != -1 && paired[byHim] != -1 && A[paired[byHim]] != -1){ // I have to choose a bad one
				idx = paired[byHim];
				int a = idx, b = byHim;
				if(b < a) swap(a, b);
				P.erase(make_pair(a, b));
			}
			else if(P.size() > 0){
				auto p = P.begin();
				int a = (*p).first, b = (*p).second;
				idx = a;
				if(A[b] > A[a]) idx = b;
				P.erase(p);
			} else{
				while(A[V[last].second] == -1) last++;
				idx = V[last].second;
			}
			printf("%d\n", idx);
			fflush(stdout);
			A[idx] = -1;
		} else{ // Judge
			scanf("%d", &byHim);
			if(byHim == -1) break;
			A[byHim] = -1;
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
