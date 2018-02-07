//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
const int MAX = (int)1e5;
int k, a[MAX], n[MAX], N;

int mInv(int a, int n){
	if(__gcd(a, n) != 1) return -1;
	int n0 = n, t, q, x0 = 0, x1 = 1;
	if(n == 1) return 0;
	while(a > 1){
		q = a/n;
		t = n;
		n = a%n;
		a = t;
		t = x0;
		x0 = x1-q*x0;
		x1 = t;
	}
	if(x1 < 0) x1 += n0;
	return x1;
}

int CRT(){
	int gg = 0;
	for(int i=0; i<k; i++){
		int Ni = N/n[i];
		gg = (gg + (((ll)a[i]*Ni)%N*mInv(Ni, n[i]))%N)%N;
	}
	return gg;
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d", &k) == 1){
		N = 1;
		for(int i=0; i<k; i++){
			scanf("%d %d", &a[i], &n[i]);
			N *= n[i];
		}
		printf("x = %d\n", CRT());
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
