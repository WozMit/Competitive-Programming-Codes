//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, A[100005];
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		for(int i=0; i<n; i++){
			if(!i) printf("%d %d\n", A[i+1]-A[i], A[n-1]-A[i]);
			else if(i == n-1) printf("%d %d\n", A[i]-A[i-1], A[i]-A[0]);
			else printf("%d %d\n", min(A[i]-A[i-1], A[i+1]-A[i]), max(A[n-1]-A[i], A[i]-A[0]));
		}
	}
	return 0;
}