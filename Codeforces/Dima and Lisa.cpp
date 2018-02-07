//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
using namespace std;
const int MAX_VAL = 1000005;
bitset<MAX_VAL> prime;
vector<int> primes;

void Sieve(){
	prime.set();
	prime[0] = prime[1] = 0;
	primes.push_back(2);
	for(int i=4; i<MAX_VAL; i+=2) prime[i] = 0;
	for(int i=3; i*i<MAX_VAL; i+=2){
		if(prime[i]){
			for(int j=i*i; j<MAX_VAL; j+=2*i) prime[j] = 0;
			primes.push_back(i);
		}
	}
}

int main() {
	int n;
	Sieve();
	while(scanf("%d", &n) == 1){
		bool flag = true;
		if(prime[n]){
			printf("1\n");
			printf("%d\n", n);
			flag = false;
		}
		for(int i=0; flag; i++){
			int a = primes[i];
			int b = n-a;
			if(prime[b]){
				printf("2\n");
				printf("%d %d\n", a, b);
				flag = false;
			}
			else{
				for(int j=0; flag; j++){
					int c = b-primes[j];
					if(prime[c]){
						printf("3\n");
						printf("%d %d %d\n", a, c, primes[j]);
						flag = false;
					}
				}
			}
		}
	}
	return 0;
}