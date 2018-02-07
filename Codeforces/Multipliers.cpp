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
#define db(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
const int mod = (ll) 1e9+7;
map<int, int> ex;

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int m;
	while(scanf("%d", &m) == 1){
		while(m--){
			int x;
			scanf("%d", &x);
			ex[x]++;
		}
		for(map<int,int>::iterator i = ex.begin(); i!=ex.end(); i++){
			int p = i->first, al = i->second;
		}
		ex.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}