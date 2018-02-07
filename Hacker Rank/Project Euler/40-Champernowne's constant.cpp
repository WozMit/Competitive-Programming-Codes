
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
typedef long long int ll;
using namespace std;
int dig[30];
ll pw10[20], x;

int getd2(ll idx, ll n){
	int i=0;
	while(n) dig[i++] = n%10, n /= 10;
	return dig[i-1-idx];
}

int getd(ll idx){
	idx--;
	for(int len=1; len<19; len++){
		ll num = pw10[len]-pw10[len-1];
		if(idx < num*len) return getd2(idx%len, pw10[len-1]+idx/len);
		idx -= num*len;
	}
	return idx;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	pw10[0] = 1;
	for(int i=1; i<20; i++) pw10[i] = pw10[i-1]*10;
	int t;
	scanf("%d", &t);
	while(t--){
		int gg = 1;
		for(int i=0; i<7; i++) scanf("%lld", &x), gg *= getd(x);
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
