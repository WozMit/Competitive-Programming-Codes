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
typedef long long int ll;
const int MAX = (int)1e5+5;
int A[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, m;
	while(scanf("%d %d", &n, &m) == 2){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		sort(A, A + n);
		ll gg = 0L;
		int pos = 0;
		for(int i=0; i<n; i++){
			if(A[i] > pos) pos++;
			gg += A[i] - 1;
		}
		gg -= A[n - 1] - pos;
		printf("%I64d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
