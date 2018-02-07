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
const int MAX = (int)1e5+5;
const double tau = 4*acos(0);
int A[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		sort(A, A+n);
		int er = A[n-1], el = A[n-2], sum_prod = er*el;
		bool right = true;
		for(int i=n-3; i>=0; i--){
			if(right) sum_prod += A[i]*er, er = A[i];
			else sum_prod += A[i]*el, el = A[i];
			right = !right;
		}
		sum_prod += el*er;
		printf("%.3f\n", sin(tau/n)*sum_prod/2.0);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
