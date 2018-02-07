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
const int MAX = 1005;
int n, k, A[MAX];

void Next_permutation(){
	bool Marked[n+1];
	for(int i=1; i<=n; i++) Marked[i] = false;
	bool next = true;
	for(int i=0; next && i<n-1; i++){
		Marked[A[i]] = true;
		bool flag = true;
		for(int j=n, pos=i+1;flag && j; j--)
			if(!Marked[j]){
				if(A[pos] == j) pos++;
				else flag = false;
			}
		if(i == n-2 && A[i] < A[i+1]) swap(A[i], A[i+1]), flag = false;
		if(flag){
			Marked[A[i]] = false;
			int val = (A[i]%n)+1;
			while(Marked[val]) val = (val%n)+1;
			A[i] = val;
			Marked[val] = true;
			for(int j=1, pos=i+1; j<=n, pos<n; j++)
				if(!Marked[j]) A[pos++] = j;
			next = false;
		}
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &k) == 2)
		while(k--){
			for(int i=0; i<n; i++) scanf("%d", &A[i]);
			Next_permutation();
			for(int i=0; i<n-1; i++) printf("%d ", A[i]);
			printf("%d\n", A[n-1]);
		}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
