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
int f[10], n;

bool Check(int n){
	int t = n, gg = 0;
	while(t) gg += f[t%10], t /= 10;
	return gg%n == 0;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	f[0] = 1;
	for(int i=1; i<10; i++) f[i] = i*f[i-1];
	scanf("%d", &n);
	int gg = 0;
	for(int i=10; i<n; i++)
		if(Check(i)) gg += i;
	printf("%d\n", gg);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
