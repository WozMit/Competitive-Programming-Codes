//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <map>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
string s;

bool Stop(){
	string t = "";
	for(int i=0; i<s.size(); i++) t += tolower(s[i]);
	return t == "arceus";
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(cin >> s){
		if(Stop()) return 0;
		map<char, int> M;
		int maxi = 0;
		for(int i=0; i<s.size(); i++) maxi = max(maxi, ++M[s[i]]);
		bool flag = false;
		for(int i=0;!flag && i<s.size(); i++)
			if(M[s[i]] == maxi){
				char c = tolower(s[i]);
				if(c == 'r' || c == 'e' || c == 'd') flag = true;
			}
		cout << s;
		if(flag) cout << " YES\n";
		else cout << " NO\n";
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
