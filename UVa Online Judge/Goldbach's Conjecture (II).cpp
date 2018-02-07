#include <cstdio>
#include <bitset>
using namespace std;
const int n = 1000002;
bitset<n> prime;

void Sieve(){
	prime.set();
	prime[0] = prime[1] = 0;
	for(int i=4; i<n; i+=2) prime[i] = 0;
	for(int i=3; i*i<n; i+=2)
		if(prime[i])
			for(int j=i*i; j<n; j+=2*i) prime[j] = 0;
}

int main() {
	Sieve();
	int x;
	while(scanf("%d", &x) && x){
		int k = 3, gg = x == 4 ? 1:0;
		while(2*k<=x){
			if(prime[k] && prime[x-k]) gg++;
			k += 2;
		}
		printf("%d\n", gg);
	}
	return 0;
}