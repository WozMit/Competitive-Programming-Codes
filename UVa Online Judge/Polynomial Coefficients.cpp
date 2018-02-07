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
typedef long long int ll;
ll f[15];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	f[0] = f[1] = 1ll;
	for(int i=2; i<15; i++) f[i] = i*f[i-1];
	int n, k;
	while(scanf("%d %d", &n, &k) == 2){
		ll gg = 1ll;
		for(int i=0; i<k; i++){
			int x; scanf("%d", &x);
			gg *= f[x];
		}
		printf("%d\n", (int)(f[n]/gg));
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
