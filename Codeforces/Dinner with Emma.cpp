//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
const int oo = 1<<30;

int main() {
	int n, m, A[102][102];
	while(scanf("%d %d", &n, &m) == 2){
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) scanf("%d", &A[i][j]);
		int max1 = 0, max2;
		for(int i=0; i<n; i++){
			int min1 = oo;
			for(int j=0; j<m; j++) min1 = min(min1, A[i][j]);
			if(min1 > max1){
				max1 = min1;
				max2 = i;
			}
		}
		int gg = oo;
		for(int i=0; i<m; i++) gg = min(gg, A[max2][i]);
		printf("%d\n", gg);
	}
	return 0;
}