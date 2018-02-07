#include <bits/stdc++.h>
using namespace std;
const int n = 1000007;
bitset<n> prime;

void SieveEra(){
	prime.set();
	prime[0] = prime[1] = 0;
	for(int i=4; i<n; i+=2) prime[i] = 0;
	for(int i=3; i*i<n; i+=2)
		if(prime[i])
			for(int j=i*i; j<n; j+=2*i) prime[j] = 0;
}

bool Prime(int x){
	if(x == 2) return true;
	if(!(x&1) || x == 1 || !x) return false;
	for(int i=3; i*i<=x; i+=2)
		if(x%i == 0) return false;
	return true;
}

vector<int> PrimeFactors(int x){
	vector<int> F;
	while(x%2 == 0){
		F.push_back(2);
		x /= 2;
	}
	int k = 3;
	while(x > 1){
		if(prime[k])
			while(x%k == 0){
				F.push_back(k);
				x /= k;
			}
		k += 2;
	}
	return F;
}

int NumbDivisors(int n){
	int a = 0;
	while(n%2 == 0){
		n /= 2;
		a++;
	}
	int gg = a+1, k = 3;
	while(k*k <= n){
		a = 0;
		while(n%k == 0){
			n /= k;
			a++;
		}
		gg *= a+1;
		k += 2;
	}
	if(n > 1) gg *= 2;
	return gg;
}

int main() {
	SieveEra();
	return 0;
}