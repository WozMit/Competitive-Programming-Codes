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

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int a, b, A[15], x;
	while(scanf("%d", &a) && a){
		scanf("%d", &b);
		for(int i=0; i<a; i++) scanf("%d", &A[i]);
		vector<double> V;
		for(int i=0; i<b; i++){
			scanf("%d", &x);
			for(int j=0; j<a; j++) V.push_back((double)A[j]/x);
		}
		sort(V.begin(), V.end());
		double gg = 0;
		for(int i=0; i<V.size()-1; i++) gg = max(gg, V[i+1]/V[i]);
		printf("%.2f\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
