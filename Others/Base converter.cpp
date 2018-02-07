#include <bits/stdc++.h>
using namespace std;

int TenToB(int n, int b){
	if(n < b) return n;
	return (n%b)+10*TenToB(n/b, b);
}

int BToTen(int n, int b){
	int gg = 0, prod = 1;
	while(n){
		gg += (n%10)*prod;
		n /= 10;
		prod *= b;
	}
	return gg;
}

int Convert(int n, int from, int to){
	return TenToB(BToTen(n, from), to);
}

int main() {
	return 0;
}