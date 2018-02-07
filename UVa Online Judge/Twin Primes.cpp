#include <cstdio>
#include <bitset>
using namespace std;
const int n = 20000007;
bitset<n> prime;
pair<int, int> A[100005];

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
	int x, max = 1;
	A[1] = make_pair(3, 5);
	while(scanf("%d", &x) == 1){
		if(x > max){
			int k = A[max].second;
			for(int i=max+1; i<=x; i++){
				while(1){
					if(prime[k] && prime[k+2]){
						A[i] = make_pair(k, k+2);
						break;
					}
					k += 2;
				}
				k += 2;
			}
			max = x;
		}
		printf("(%d, %d)\n", A[x].first, A[x].second);
	}
	return 0;
}