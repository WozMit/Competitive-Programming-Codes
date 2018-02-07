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
const int MAX = 400;
int A[MAX], sum[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		sum[0] = A[0];
		for(int i=1; i<n; i++) sum[i] = A[i] + sum[i - 1];
		int mini = 1<<30;
		for(int i=0; i<n; i++)
			for(int j=i; j<n; j++)
				if(abs(360 - 2*(sum[j] - (i ? sum[i-1]:0))) < mini) mini = abs(360 - 2*(sum[j] - (i ? sum[i-1]:0)));
		printf("%d\n", mini);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
