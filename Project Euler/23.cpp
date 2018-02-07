#include <bits/stdc++.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
const int MAX = (int)1e5+5;
int p[MAX];
bitset<MAX> prime;

int pow(int a, int b){
	int gg = 1;
	while(b){
		if(b&1) gg *= a;
		a *= a;
		b >>= 1;
	}
	return gg;
}

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

ll D(int n){
	ll gg = 1ll, t = n;
	while(n > 1){
		int pf = p[n], k = 0;
		while(n%pf == 0) n /= pf, k++;
		gg *= ((ll)pow(pf, k+1)-1ll)/(ll)(pf-1ll);
	}
	return gg-t;
}

int main() {
	Sieve();
	vector<int> A;
	for(int i=12; i<28124; i++)
		if(D(i) > (ll)i) A.push_back(i);
	set<int> S;
	for(int i=0; i<A.size(); i++)
		for(int j=i; j<A.size(); j++) S.insert(A[i]+A[j]);
	int gg = 0;
	for(int i=1; i<28124; i++)
		if(!S.count(i)) gg += i;
	printf("%d\n", gg);
	return 0;
}
