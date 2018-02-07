//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
const int MAX = 3001;
struct trip{
	int a, b, c, s, p;
	trip(int pa, int pb, int pc){ a = pa; b = pb; c = pc; s = a+b+c; p = a*b*c; }
};

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	vector<trip> V;
	for(int a=1; a<MAX/3; a++)
		for(int b=a+1; a+b+(int)sqrt(a*a+b*b) < MAX; b++){
			int p = a*a+b*b;
			if(sqrt(p) == (int)sqrt(p)) V.push_back(trip(a, b, sqrt(p)));
		}
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int gg = -1;
		for(int i=0; i<V.size(); i++)
			if(V[i].s == n) gg = max(gg, V[i].p);
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
