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
const int MAX = 30;
int start[MAX], thend[MAX], deg[MAX];
string s;

void dfs(int from, int to){
	int i = from + 1, j = thend[s[i] - 65];
	while(i < to){
		dfs(i, j);
		deg[s[from] - 65]++;
		i = j + 1;
		j = thend[s[i] - 65];
	}
	if(from > 0) deg[s[from] - 65]++;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	for(int t=0; t<te; t++){
		cin >> s;
		for(int i=0; i<MAX; i++){
			start[i] = -1;
			deg[i] = 0;
		}
		for(int i=0; i<s.size(); i++){
			int letter = s[i] - 65;
			if(start[letter] == -1) start[letter] = i;
			thend[letter] = i;
		}
		dfs(0, s.size() - 1);
		printf("Case %d\n", t+1);
		for(char c = 'A'; c <= 'Z'; c++)
			if(deg[c - 65] > 0) printf("%c = %d\n", c, deg[c - 65]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
