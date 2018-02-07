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
	int n, m, A[105];
	while(scanf("%d %d", &n, &m) == 2){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		sort(A, A+n);
		int gg = 0, i = n-1;
		while(m > 0){
			m -= A[i--];
			gg++;
		}
		printf("%d\n", gg);
	}
	return 0;
}