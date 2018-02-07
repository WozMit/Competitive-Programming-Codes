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

bool Check(int n, int k){
	int t = n, gg = 0;
	while(t) gg += pow(t%10, k), t /= 10;
	return gg == n;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	/*ll sum = 0;
	for(int i=100000; i<10000000; i++)
		if(Check(i, 6)) sum += i, db(i);
	db(sum);*/
	//sum_3 = 1301
	//sum_4 = 19316
	//sum_5 = 443839
	//sum_6 = 548834
	int n, GG[] = {0, 0, 0, 1301, 19316, 443839, 548834};
	scanf("%d", &n);
	printf("%d\n", GG[n]);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
