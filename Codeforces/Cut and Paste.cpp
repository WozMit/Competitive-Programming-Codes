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
const int MAX = (int)1e6+5, p = (int)1e9+7;

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		int x; scanf("%d", &x);
		string s, c; cin >> s;
		//db("//////////////")
		//db(s);
		int l = 0, lenc;
		ll gg = s.size();
		bool flag = true;
		for(int l=1; l<=x; l++){
			//db(l)
			if(flag)
				c = s.substr(l);
				lenc = s.size() - l;
			//db(s.substr(l));
			if(s[l-1] == '2'){
				if(flag && s.size() < x + 3)
					s += c;
				else flag = false;
				//gg = (gg + (gg - l + p)%p)%p;
				gg += gg - l + p;
				gg %= p;
			}
			if(s[l-1] == '3'){
				if(flag && s.size() < x + 3)
					s += c;
				else flag = false;
				if(flag && s.size() < x + 3)
					s += c;
				else flag = false;
				gg += 2ll*(gg - l) + p;
				gg %= p;
				//gg = (gg + (2ll*(gg - l + p)%p)%p)%p;
			}
			//db(s)
		}
		//db(s.size());
		printf("%d\n", (int)gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
