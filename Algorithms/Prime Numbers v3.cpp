//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <bitset>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
const int MAX = int(1e7);
int p[MAX];
vector<int> prime;
bitset<MAX> primes;

void Sieve(){
	p[0] = p[1] = -1, p[2] = 2, p[3] = 3, p[5] = 5;
	for(int i=4; i<MAX; i+=2) p[i] = 2;
	for(int i=25; i<MAX; i+=10) p[i] = 5;
	for(int i=9; i<MAX; i+=6) p[i] = 3;
	int w[] = {4, 2, 4, 2, 4, 6, 2, 6}, c = 0;
	for(int i=7; i*i<MAX; i+=w[c++&7])
		if(!p[i]){
			p[i] = i;
			for(int j=i*i; j<MAX; j+=2*i) p[j] = i;
		}
	prime.push_back(2);
	for(int i=3; i<MAX; i+=2)
		if(p[i] == i) prime.push_back(i);
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	int x = 134;
	while(x > 1){
		cout << p[x] << " ";
		x /= p[x];
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s";
	#endif
	return 0;
}
