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
typedef long long int ll;
int k, pw10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

bool Pandigital(ll n){
	int dig = 0, count = 0, tmp;
	while(n){
		tmp = dig;
		dig = dig | 1<<(int)((n%10)-1);
		if(tmp == dig) return false;
		count++;
		n /= 10;
	}
	return dig == (1<<count)-1;
}

bool Check(int n){
	ll gg = n;
	for(int i=2; true; i++){
		gg = gg*pw10[1+(int)log10(n*i)]+n*i;
		if(gg>=pw10[k]) return false;
		if(gg >= pw10[k-1] && Pandigital(gg)) return true;
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	scanf("%d %d", &n, &k);
	for(int i=2; i<n; i++)
		if(Check(i)) printf("%d\n", i);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
