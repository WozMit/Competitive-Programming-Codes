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

int sum_dig(int x){
	int gg = 0;
	while(x > 0){
		gg += x%10;
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
	int n;
	while(scanf("%d", &n) == 1){
		vector<int> V;
		for(int i=n-90; i<n; i++)
			if(i + sum_dig(i) == n) V.push_back(i);
		printf("%d\n", V.size());
		for(int i=0; i<(int)V.size()-1; i++) printf("%d ", V[i]);
		if(V.size()) printf("%d\n", V[V.size()-1]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
