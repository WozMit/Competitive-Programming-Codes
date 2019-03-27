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
char s[MAX];
int cnt[60];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		scanf("%s", s);
		set<char> S;
		for(int i=0; i<n; i++) S.insert(s[i]);
		int tot = S.size();
		for(int i=0; i<60; i++) cnt[i] = 0;
		S.clear();
		S.insert(s[0]);
		cnt[s[0]-65]++;
		int i = 0, j = 0, gg = MAX;
		while(j < n){
			if(S.size() < tot){
				j++;
				if(j < n){
					S.insert(s[j]);
					cnt[s[j]-65]++;
				}
			}
			else{
				gg = min(gg, j - i + 1);
				if(--cnt[s[i]-65] == 0) S.erase(s[i]);
				i++;
			}
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
