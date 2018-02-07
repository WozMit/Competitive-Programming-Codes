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

bool Compare(string s, string p){
	for(int i=0; i<p.size(); i++) if(p[i] != '-' && p[i] != s[i]) return false;
	return true;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, q;
	string V[103], s;
	scanf("%d", &n);
	for(int i=0; i<n; i++) cin >> V[i];
	scanf("%d", &q);
	for(int t=0; t<q; t++){
		cin >> s;
		int gg = 0;
		printf("Word #%d: %s\n", t+1, s.c_str());
		for(int i=0; i<n; i++)
			if(s.size() == V[i].size() && Compare(V[i], s)) printf("%s\n", V[i].c_str()), gg++;
		printf("Total number of candidate words = %d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
