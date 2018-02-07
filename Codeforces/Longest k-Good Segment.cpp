//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
const int MAX = 500005;
int A[MAX], O[MAX], n, k;

int main() {
	while(scanf("%d %d", &n, &k) == 2){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		memset(O, 0, sizeof O);
		int q = 0, j = 0, gg1, gg2, val = -1;
		for(int i=0; i<=n-k; i++){
			if(i){
				O[A[i-1]]--;
				if(!O[A[i-1]]) q--;
			}
			while(j < n && q <= k){
				int x = A[j];
				if(q == k && !O[x]){
					j--;
					break;
				}
				if(!O[x]) q++;
				O[x]++;
				if(j == n-1) break;
				j++;
			}
			if(j-i > val){
				val = j-i;
				gg1 = i+1;
				gg2 = j+1;
			}
			if(j != n-1) j++;
		}
		printf("%d %d\n", gg1, gg2);
	}
	return 0;
}