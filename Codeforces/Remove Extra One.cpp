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
const int MAX = (int)1e5+5;
int n, bit[MAX], A[MAX], B[MAX], ones[MAX];

void Update(int x, int val){	//Adds value val to position x
	for(; x<=n; x += x&(-x))
		bit[x] += val;
}

int Query(int x){	//Returns the sum of [1:x]
	int gg = 0;
	for(; x>0; x -= x&(-x))
		gg += bit[x];
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d", &n) == 1){
		for(int i=1; i<=n; i++) bit[i] = 0;
		for(int i=0; i<n; i++){
			int x; scanf("%d", &x);
			A[i] = x;
			x = n - x + 1;
			B[i] = Query(x);
			Update(x, 1);
		}
		ones[n-1] = (B[n-1] == 1);
		for(int i=n-2; i>=0; i--)
			ones[i] = (B[i] == 1) + ones[i+1];
		int gg = -1, zeros = 0, maxi = -1;
		for(int i=0; i<n; i++)
			if(B[i] == 0) zeros++;
		for(int i=0; i<n; i++){
			int tot = zeros + (i < n-1 ? ones[i+1]:0) - (B[i] == 0);
			if(tot > maxi){
				maxi = tot;
				gg = A[i];
			}
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
