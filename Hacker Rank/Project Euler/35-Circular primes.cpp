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
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = (int)1e6+5;
bitset<MAX> prime;
vector<int> primes;
int A[8], k;

void Sieve(){
	prime.set();
	prime[0] = prime[1] = false;
	for(int i=4; i<MAX; i+=2) prime[i] = false;
	for(int i=3; i<MAX; i+=2)
		if(prime[i]) for(ll j=(ll)i*i; j<MAX; j+=2*i) prime[j] = false;
	primes.push_back(2);
	for(int i=3; i<MAX; i+=2) if(prime[i]) primes.push_back(i);
}

int ToNumber(){
	int gg = 0;
	for(int i=k-1; i>=0; i--) gg = gg*10+A[i];
	return gg;
}

void Rotate(){
	int t = A[0];
	A[0] = A[k-1];
	for(int i=1; i<k; i++) swap(t, A[i]);
}

bool Check(int n){
	int t = n;
	for(k=0; t; k++) A[k] = t%10, t /= 10;
	bool flag = true;
	for(int i=0; flag && i<k; i++) Rotate(), flag &= prime[ToNumber()];
	return flag;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	int n;
	scanf("%d", &n);
	int gg = 0;
	for(int i=0; primes[i]<n; i++)
		if(Check(primes[i])) gg += primes[i];
	printf("%d\n", gg);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
