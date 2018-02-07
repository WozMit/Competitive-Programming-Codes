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
const int p = 131071;
typedef long long int ll;

int exp(int a, int b){
	int gg = 1;
	while(b){
		if(b&1) gg = ((ll)gg*a)%p;
		a = ((ll)a*a)%p;
		b >>= 1;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	char c;
	int n;
	while(cin >> c){
		n = c-'0';
		while(cin >> c){
			if(c == '#') break;
			n = (n*2 + c-'0')%p;
		}
		if(n) printf("NO\n");
		else printf("YES\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
