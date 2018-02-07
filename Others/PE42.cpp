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
	string s, t;
	cin >> s;
	vector<int> V;
	for(int i=1, pos = 1; i<s.size(); i++)
		if(s[i] == '"'){
			t = s.substr(pos, i-pos);
			i += 3;
			pos = i;
			int gg = 0;
			for(int j=0; j<t.size(); j++) gg += (int)t[j]-64;
			V.push_back(gg);
		}
	printf("%d\n", V.size());
	for(int i=0; i<V.size(); i++) printf("%d\n", V[i]);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
