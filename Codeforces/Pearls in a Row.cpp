//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <map>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
const int MAX = 300005;
map<int, bool> F;
vector<pair<int, int> > V;
int n, A[MAX];

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		int k = 0, i = 0;
		bool flag = false;
		for(int j=0; j<n; j++){
			int x = A[j];
			if(F[x]){
				if(flag){
					V.push_back(make_pair(k, i));
					k = i+1;
				}
				flag = true;
				i = j;
				F.clear();
			}
			else F[x] = true;
		}
		if(i) V.push_back(make_pair(k, n-1));
		if(V.empty()) printf("-1\n");
		else{
			printf("%d\n", V.size());
			for(int i=0; i<V.size(); i++) printf("%d %d\n", V[i].first+1, V[i].second+1);
		}
		F.clear();
		V.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}