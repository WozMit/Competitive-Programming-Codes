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
int n, m;

struct par{
	int x;
	string s;
	par(int px, string ps){ x = px, s = ps;	}
	bool operator <(par b)const{ return x < b.x; }
};

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &m) == 2){
		string s;
		vector<par> V;
		while(m--){
			cin >> s;
			int gg = 0;
			for(int i=0; i<n-1; i++)
				for(int j=i+1; j<n; j++) if(s[i] > s[j]) gg++;
			V.push_back(par(gg, s));
		}
		stable_sort(V.begin(), V.end());
		for(int i=0; i<V.size(); i++) cout << V[i].s << "\n";
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
