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
const int MAX = (int)1e5+5;
int A[MAX], B[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, k, m;
	while(scanf("%d %d %d", &n, &k, &m) == 3){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		vector<pair<int, int> > V(n);
		for(int i=0; i<n; i++) V[i] = make_pair(A[i]%m, A[i]);
		sort(V.begin(), V.end());
		int idx = 0;
		bool flag = false;
		while(idx + k - 1 < n && !flag){
			if(V[idx].first == V[idx + k - 1].first) flag = true;
			else idx++;
		}
		if(flag){
			puts("Yes");
			while(k-- > 1) printf("%d ", V[idx++].second);
			printf("%d\n", V[idx].second);
		}
		else puts("No");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
