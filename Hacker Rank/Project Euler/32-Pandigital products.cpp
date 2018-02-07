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
typedef long long int ll;

bool Check(ll n, int d){
	int dig = 0, count = 0, tmp;
	while(n){
		tmp = dig;
		dig = dig | 1<<(int)((n%10)-1);
		if(tmp == dig) return false;
		count++;
		n /= 10;
	}
	return count == d && dig == (1<<count)-1;
}

ll Concat(ll a, ll b){
	ll c = b;
	while(c) a *= 10, c /= 10;
	return a+b;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	/*set<ll> S;
	for(ll a = 10; a<100; a++)
		for(ll b = 100; b<1000; b++)
			if(Check(Concat(a, Concat(b, a*b)), 9)) S.insert(a*b);
	ll gg = 0;
	for(set<ll>::iterator i=S.begin(); i!=S.end(); i++) gg += *i;
	db(gg);*/
	int GG[] = {12, 52, 162, 0, 13458, 45228}, n;
	while(scanf("%d", &n) == 1) printf("%d\n", GG[n-4]);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
