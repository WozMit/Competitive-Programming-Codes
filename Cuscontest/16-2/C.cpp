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
	string s1 = " abcdefghijklmnopqrstuvwxyz", s2 = " yhesocvxduiglbkrztnwjpfmaq", s;
	int t;
	scanf("%d", &t);
	cin.ignore();
	while(t--){
		getline(cin, s);
		for(int i=0; i<s.size(); i++) s[i] = s2[s1.find(s[i])];
		printf("%s\n", s.c_str());
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}