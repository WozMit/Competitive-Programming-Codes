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
const int MAX = (int)2e5 + 7;
int A[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		sort(A, A+n);
		vector<int> B;
		for(int i=0; i<n; i++){
			int pos = lower_bound(A, A+n, A[i] + 1) - A;
			B.push_back(pos - i);
			i = pos - 1;
		}
		sort(B.begin(), B.end());
		for(int i=B.size() - 1; i >= 1; i--)
			B[i-1] = min(B[i-1], B[i] / 2);
		int gg = 0;
		for(int i=0; i<B.size(); i++)
			gg = max(gg, B[i] * ((1<<(B.size() - i)) - 1));
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
