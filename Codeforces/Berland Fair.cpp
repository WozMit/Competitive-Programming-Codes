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
const int MAX = (int)2e5 + 7;
int A[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n; ll t;
	while(scanf("%d %lld", &n, &t) == 2){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		int mini = A[0];
		for(int i=1; i<n; i++) mini = min(mini, A[i]);
		ll gg = 0;
		while(t >= mini){
			ll numb = 0ll, tp = t;
			for(int i=0; i<n; i++)
				if(A[i] <= tp){
					tp -= A[i];
					numb++;
				}
			ll cost = t - tp;
			gg += t / (t - tp) * numb;
			t %= cost;
		}
		printf("%lld\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
