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
		string t = "", gg = "";
		int C[30];
		memset(C, 0, sizeof C);
		for(int i=0; i<s.size(); i++) C[(s[i]-97)]++;
		int point = 0;
		while(point < 26 && C[point] == 0) point++;
		for(int i=0; i<s.size(); i++){
			if(s[i] == (char)(point+97)){
				gg += s[i];
				C[point]--;
				while(point < 26 && C[point] == 0) point++;
			}
			else t += s[i];
		}
		for(int i=t.size()-1; i>=0; i--) gg += t[i];
		printf("%s\n", gg.c_str());
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
