#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = (int)1e6+6;
int p[MAX];
bitset<MAX> prime;
void Sieve(){
	prime.set();
	prime[0] = prime[1] = false;
	p[2] = 2;
	for(int i=4; i<MAX; i+=2) prime[i] = false, p[i] = 2;
	for(int i=3; i<MAX; i+=2)
		if(prime[i]){
			p[i] = i;
			for(ll j = (ll)i*(ll)i; j<MAX; j+=2ll*i)
				if(prime[j]) prime[j] = false, p[j] = i;
		}
}

int F(int n){
	int loc = 1;
	while(n > 1){
		int pf = p[n];
		loc = pf;
		while(n%pf == 0) n /= pf;
	}
	return loc;
}
int main(){
	Sieve();
	int n;
	while(scanf("%d", &n) == 1){
		int gg = 0;
		while(n){
			n -= F(n);
			gg++;
		}
		printf("%d\n", gg);
	}
	return 0;
}
