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
typedef long long int ll;

bool Palindrome(ll x){
	char st[15];
	sprintf(st, "%lld", x);
	string s = st;
	for(int i=0; 2*i<=s.size(); i++)
		if(s[i] != s[s.size() - i - 1]) return false;
	return true;
}

ll Reverse(ll x){
	char st[15];
	sprintf(st, "%lld", x);
	string s = st;
	reverse(s.begin(), s.end());
	sscanf(s.c_str(), "%lld", &x);
	return x;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		ll n; scanf("%lld", &n);
		int gg = 0;
		do{
			n += Reverse(n);
			gg++;
		}while(!Palindrome(n));
		printf("%d %lld\n", gg, n);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
