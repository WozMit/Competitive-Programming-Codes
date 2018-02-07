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
const int MAX = (int)1e5+5, oo = 1<<30;
int e[MAX], o[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, x;
	while(scanf("%d", &n) == 1){
		scanf("%d", &x);
		e[0] = x&1 ? -oo:x;
		o[0] = x&1 ? x:(-oo-1);
		for(int i=1; i<n; i++){
			scanf("%d", &x);
			if(x&1){
				o[i] = max(x, max(o[i-1], x + e[i-1]));
				e[i] = max(e[i-1], x + o[i-1]);
			}
			else{
				e[i] = max(x, max(e[i-1], x + e[i-1]));
				o[i] = max(o[i-1], x + o[i-1]);
			}
		}
		printf("%d\n", o[n-1]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
