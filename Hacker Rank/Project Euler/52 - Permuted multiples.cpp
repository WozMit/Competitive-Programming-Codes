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

string getMask(int x){
	string gg = "000000000";
	while(x > 0){
		int d = x%10;
		gg[d] = (gg[d] - '0' + 1) + '0';
		x /= 10;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, k;
	while(scanf("%d %d", &n, &k) == 2){
		for(int i=1; i<=n; i++){
			string mask = getMask(i);
			bool flag = true;
			for(int j=2; j<=k && flag; j++)
				if(getMask(i*j) != mask) flag = false;
			if(flag){
				for(int j=1; j<=k; j++) printf("%d ", i*j);
				puts("");
			}
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
