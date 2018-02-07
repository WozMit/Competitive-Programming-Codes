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

string modify(string s){
	string gg = "";
	for(int i=0; i<s.size(); i++){
		char c = s[i];
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) gg += tolower(c);
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n; scanf("%d", &n);
	string s, t;
	set<string> S;
	while(cin >> s){
		t = modify(s);
		if(t != "") S.insert(t);
	}
	printf("%d\n", S.size());
	for(set<string>::iterator it=S.begin(); it!=S.end(); it++) printf("%s\n", (*it).c_str());
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
