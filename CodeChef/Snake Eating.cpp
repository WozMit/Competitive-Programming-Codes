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
typedef long long int ll;
const int MAX = (int)1e5+5;
int A[MAX];
ll S[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		int n, q, v; scanf("%d %d", &n, &q);
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		sort(A, A+n);
		S[0] = A[0];
		for(int i=1; i<n; i++) S[i] = S[i-1] + A[i];
		while(q--){
			scanf("%d", &v);
			int pos = lower_bound(A, A+n, v) - A - 1, gg = n - 1 - pos;
			int i = 0, j = pos + 1;
			while(j - i > 1){
				int mid = i + (j-i)/2;
				if((ll)v*(pos-mid+1) - S[pos] + S[mid-1] > mid) i = mid;
				else j = mid;
			}
			printf("%d\n", gg + pos - j + 1);
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
