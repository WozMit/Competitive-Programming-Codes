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
	string s;
	while(cin >> s){
		int gg = 0;
		int ans = 0;
		for(int j=1; j<s.size(); j++)
			if(s[j-1] == 'V' && s[j] == 'K') ans++;
		gg = max(gg, ans);
		for(int i=0; i<s.size(); i++){
			if(s[i] == 'V') s[i] = 'K';
			else if(s[i] == 'K') s[i] = 'V';
			ans = 0;
			for(int j=1; j<s.size(); j++)
				if(s[j-1] == 'V' && s[j] == 'K') ans++;
			gg = max(gg, ans);
			if(s[i] == 'V') s[i] = 'K';
			else if(s[i] == 'K') s[i] = 'V';
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
