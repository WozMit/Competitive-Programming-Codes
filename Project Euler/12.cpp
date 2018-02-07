#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

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
	int k = 1, sum = 1;
	while(NumbDivisors(sum) <= 500) sum += ++k;
	cout << sum << endl;
	return 0;
}