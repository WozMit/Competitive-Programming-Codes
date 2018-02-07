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
	int te; scanf("%d", &te);
	while(te--){
		string s, gg = "a"; cin >> s;
		int n = s.size();
		for(int m=1; m < (1<<n); m++){
			string t = "";
			for(int i=0; i<n; i++)
				if(m&(1<<i) > 0) t += s[i];
			string h = t;
			reverse(h.begin(), h.end());
			if(t > gg && h == t) gg = t;
		}
		db(gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
