//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int a;
	while(scanf("%d", &a) == 1 && a){
		vector<int> V;
		V.push_back(a);
		while(scanf("%d", &a) == 1 && a) V.push_back(a);
		int gcd;
		for(int i=0; i<V.size(); i++)
			for(int j=i+1; j<V.size(); j++)
				if(j == 1) gcd = max(V[0]-V[1], V[1]-V[0]);
				else gcd = __gcd(gcd, max(V[i]-V[j], V[j]-V[i]));
		printf("%d\n", gcd);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
