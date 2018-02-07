//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef unsigned long long int ll;

ll cont(ll x){
	for(ll i=0; (1ll<<i) <= x; i++)
		if(x&(1ll<<i)) return i;
	return 0;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	string s;
	while(cin >> s){
		ll end = 0ll;
		for(int i=0; i<s.size(); i++)
			if(s[i] == '1') end |= 1ll<<(s.size() - i - 1);
		ll state = 0, gg = 0ll;
		while(state != end){
			state ^= gg&1 ? (1ll << (cont(state)+1ll)):1;
			gg++;
		}
		printf("%lld\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
