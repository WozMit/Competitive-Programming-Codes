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
int n;

int D(int p){
	int gg = 0;
	ll exp = p;
	while(exp <= n) gg += n/exp, exp *= p;
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int m;
	while(scanf("%d %d", &n, &m) == 2){
		int temp = m;
		bool flag = true;
		for(int i=2; flag && (ll)i*i<=m; i++)
			if(m%i == 0){
				int k = 0, d = D(i);
				while(flag && m%i == 0){
					m /= i;
					k++;
					if(k > d) flag = false;
				}
			}
		if(m != 1 && !D(m)) flag = false;
		if(flag) printf("%d divides %d!\n", temp, n);
		else printf("%d does not divide %d!\n", temp, n);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
