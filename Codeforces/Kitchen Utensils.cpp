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
const int MAX = 105;
int A[MAX], cnt[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, k;
	while(scanf("%d %d", &n, &k) == 2){
		for(int i=0; i<MAX; i++) cnt[i] = 0;
		for(int i=0; i<n; i++){
			int x; scanf("%d", &x);
			cnt[x]++;
		}
		vector<int> V;
		for(int i=0; i<MAX; i++)
			if(cnt[i]) V.push_back(cnt[i]);
		int maxi = 0;
		for(int e : V) maxi = max(maxi, e);
		int dishes = ceil(1.0 * maxi / k);
		printf("%d\n", dishes * k * V.size() - n);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
