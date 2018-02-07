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
	int n, A[100005];
	while(scanf("%d", &n) == 1){
		int sum = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &A[i]);
			sum += A[i];
		}
		sum = int(ceil(double(sum)/double(n)));
		int gg = 0;
		for(int i=0; i<n; i++)
			if(A[i] > sum) gg += A[i]-sum;
		printf("%d\n", gg);
	}
	return 0;
}