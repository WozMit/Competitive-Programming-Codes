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
const int MAX = (int)1e5+5;
int A[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, x, k;
	while(scanf("%d %d %d", &n, &x, &k) == 3){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		sort(A, A+n);
		ll gg = 0ll;
		for(int i=0; i<n; i++){
			int pos = lower_bound(A, A+n, A[i]) - A;
			int search = k + (A[pos]-1)/x;
			int l = pos, r = n;
			while(r - l > 1){
				int mid = l + (r - l)/2;
				if(A[mid]/x <= search) l = mid;
				else r = mid;
			}
			if(A[l]/x != search) continue;
			int up = l;
			l = pos-1, r = up;
			while(r - l > 1){
				int mid = l + (r - l)/2;
				if(A[mid]/x < search) l = mid;
				else r = mid;
			}
			if(A[r]/x != search) continue;
			int down = r;
			gg += up - down + 1;
		}
		printf("%I64d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
