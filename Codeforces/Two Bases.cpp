//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
	int n, b, A[12];
	while(scanf("%d %d", &n, &b) == 2){
		for(int i=n-1; i>=0; i--) scanf("%d", &A[i]);
		ll x = A[0], pot = b;
		for(int i=1; i<n; i++){
			x += A[i]*pot;
			pot *=b;
		}
		scanf("%d %d", &n, &b);
		for(int i=n-1; i>=0; i--) scanf("%d", &A[i]);
		ll y = A[0];
		pot = b;
		for(int i=1; i<n; i++){
			y += A[i]*pot;
			pot *=b;
		}
		if(x < y) printf("<\n");
		else if(x > y) printf(">\n");
		else printf("=\n");
	}
	return 0;
}