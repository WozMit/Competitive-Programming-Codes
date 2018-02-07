//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, m, A[200005];
	while(scanf("%d %d", &n, &m) == 2){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		vector<int> V(A, A+n);
		sort(V.begin(), V.end());
		vector<int>::iterator idx;
		int gg = 0;
		for(int i=0; i<n; i++){
			idx = upper_bound(V.begin(), V.end(), V[i]);
			gg += n-(idx-V.begin());
		}
		printf("%d\n", gg);
	}
	return 0;
}