//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <set>
#include <map>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = (int)1e7+5;
int g[MAX];

int calc(int n){
	if(n == 1) return 0;
	int gg = -1;
	for(int i=1; 2*i<=n; i++)
		if(__gcd(i, n-i) == 1){
			if(gg == -1) gg = calc(i)^calc(n-i);
			else gg ^= calc(i)^calc(n-i);
		}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	memset(g, -1, sizeof g);
	db(calc(10));
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
