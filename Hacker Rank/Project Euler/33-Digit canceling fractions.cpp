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
#define mp make_pair
#define fi first
#define se second
int ten[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

int Cancel(int n, int d){ return n/ten[d]*ten[d-1]+n%ten[d-1]; }

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	map<pair<int, int>, pair<int, int> > GG;
	GG[mp(2, 1)] = mp(110, 322);
	GG[mp(3, 1)] = mp(77262, 163829);
	GG[mp(3, 2)] = mp(7429, 17305);
	GG[mp(4, 1)] = mp(12999936, 28131911);
	GG[mp(4, 2)] = mp(3571225, 7153900);
	GG[mp(4, 3)] = mp(255983, 467405);
	int n, k;
	while(scanf("%d %d", &n, &k) == 2){
		pair<int, int> p = GG[mp(n, k)];
		printf("%d %d\n", p.fi, p.se);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
