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
typedef long long int ll;
const int MAX = (int)2e5;
int A[MAX], B[MAX];
ll C[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		for(int i=0; i<n; i++) B[i] = A[i];
		sort(B, B+n);
		C[0] = B[0];
		for(int i=1; i<n; i++) C[i] = C[i - 1] + B[i];
		vector<int> G, M;
		if(C[n - 2] > B[n - 1]){
			int from = lower_bound(B, B+n-1, C[n - 2] - B[n - 1]) - B;
			int to = lower_bound(B, B+n-1, C[n - 2] - B[n - 1] + 1) - B - 1;
			if(from < n - 1 && to < n - 1 && B[from] == B[to]){
				for(; from <= to; from++) G.push_back(B[from]);
			}
		}
		if(n > 2 && B[n - 2] == C[n - 3]) G.push_back(B[n - 1]);
		printf("%d\n", G.size());
		sort(G.begin(), G.end());
		for(int i=0; i<n; i++)
			if(binary_search(G.begin(), G.end(), A[i])) printf("%d ", i + 1);
		if(G.size()) printf("\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
