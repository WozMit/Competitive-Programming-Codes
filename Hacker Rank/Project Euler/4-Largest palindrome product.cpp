//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <set>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

bool P(int n){
	stringstream s1;
	s1 << n;
	string s = s1.str();
	int i=0, j=s.size()-1;
	while(i<=j)
		if(s[i++] != s[j--]) return false;
	return true;
}

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	set<int> S;
	for(int i=100; i<1000; i++)
		for(int j=100; j<=i; j++)
			if(P(i*j)) S.insert(i*j);
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int gg = 0;
		for(set<int>::iterator i=S.begin(); i!=S.end(); i++)
			if(*i < n) gg = max(gg, *i);
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
