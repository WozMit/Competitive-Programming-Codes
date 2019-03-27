//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = (int)1e5+5;
int startsat[MAX], endsat[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		string s; cin >> s;
		int totG = 0;
		for(int i=0; i<n; i++)
			if(s[i] == 'G'){
				endsat[i] = 1 + (i ? endsat[i - 1] : 0);
				totG++;
			}
			else endsat[i] = 0;
		startsat[n - 1] = (s[n - 1] == 'G');
		for(int i = n - 2; i>=0; i--)
			if(s[i] == 'G')
				startsat[i] = 1 + startsat[i + 1];
			else startsat[i] = 0;
		int gg = 0;
		for(int i=0; i<n; i++)
			if(s[i] == 'S'){
				int un = (i + 1 < n ? startsat[i + 1]:0) + (i - 1 >= 0 ? endsat[i - 1]:0);
				gg = max(gg, un + (un == totG ? 0 : 1));
			}
		if(totG == n) gg = n;
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
