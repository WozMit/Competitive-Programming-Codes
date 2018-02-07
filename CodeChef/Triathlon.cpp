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
const int MAX = (int)2e5+5;
int A[MAX], B[MAX];

void QuickSort(int low, int high){
	if(low < high){
		int p = high, i = low, j = high-1;
		while(i <= j)
			if(B[i] < B[p] && B[j] > B[p]){
				swap(A[i], A[j]);
				swap(B[i++], B[j--]);
			}
			else if(B[i] < B[p]) j--;
			else if(B[j] > B[p]) i++;
			else i++, j--;
		swap(A[i], A[p]);
		swap(B[i], B[p]);
		QuickSort(low, i-1);
		QuickSort(i+1, high);
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		int x;
		for(int i=0; i<n; i++){
			scanf("%d", &A[i]);
			scanf("%d", &B[i]);
			scanf("%d", &x);
			B[i] += x;
		}
		QuickSort(0, n-1);
		int gg = 0, sum = 0;
		for(int i=0; i<n; i++){
			sum += A[i];
			gg = max(gg, sum+B[i]);
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
