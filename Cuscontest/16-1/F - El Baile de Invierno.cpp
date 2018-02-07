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
const int MAX = (int)1e5;
int n, m, k;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t, A[MAX], B[MAX];
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &m, &k);
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		for(int i=0; i<m; i++) scanf("%d", &B[i]);
		sort(A, A+n);
		sort(B, B+m);
		int i = 0, j = 0, gg = 0;
		while(i != n && j != m)
			if(abs(A[i]-B[j]) <= k) gg++, i++, j++;
			else if(A[i] < B[j]) i++;
			else j++;
		printf("# maximo de parejas equilibradas = %d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
