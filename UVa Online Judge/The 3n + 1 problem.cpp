//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <map>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = (int)1e6+7;
int fuck[MAX];
map<ll, int> c1;

int Fuck(ll n){
	if(n == 1) return 1;
	if(n < MAX && fuck[n] != -1) return fuck[n];
	if(c1.count(n)) return c1[n];
	int gg = 1 + (n&1 ? Fuck(3*n+1):Fuck(n/2));
	if(n >= MAX) c1[n] = gg;
	else fuck[n] = gg;
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	memset(fuck, -1, sizeof fuck);
	for(int i=1; i<MAX; i++) fuck[i] = Fuck(i);
	int i, j;
	while(scanf("%d %d", &i, &j) == 2){
		int m = max(i, j), gg = Fuck(m);
		for(int k=min(i, j); k<m; k++) gg = max(gg, Fuck(k));
		printf("%d %d %d\n", i, j, gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
