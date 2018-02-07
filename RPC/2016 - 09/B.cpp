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

struct Prop{
	int f, t, p;
	Prop(int pf, int pt, int pp){ f = pf, t = pt, p = pp; }
	bool Check(int m){ return (((m>>f)&1) ^ ((m>>t)&1) ^ p); }
};

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t, n, q;
	scanf("%d", &t);
	for(int te=0; te<t; te++){
		scanf("%d %d", &n, &q);
		int from, to;
		char prop;
		vector<Prop> P;
		while(q--){
			scanf("%d %d %c", &from, &to, &prop);
			P.push_back(Prop(from, to, prop == 'T' ? 1:0));
		}
		int gg = 0;
		for(int i=0; i<(1<<n); i++){
			bool flag = true;
			for(int j=0; flag && j<P.size(); j++) flag &= P[j].Check(i);
			if(flag) gg++;
		}
		printf("Case #%d: %d\n", te+1, gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
