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
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int k;
	while(scanf("%d", &k) == 1){
		vector<pair<int, int> > V;
		for(int x=k+1; x<=2*k; x++)
			if((x*k)%(x-k) == 0) V.push_back(make_pair(x, (x*k)/(x-k)));
		printf("%d\n", V.size());
		for(int i=0; i<V.size(); i++) printf("1/%d = 1/%d + 1/%d\n", k, V[i].second, V[i].first);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
