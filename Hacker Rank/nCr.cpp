//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
int Co11[40][40], Co13[40][40], Co37[40][40];

int exp(int a, int b, ll mod = 1ll<<63){
	int gg = 1;
	while(b){
		if(b&1) gg = (ll)gg*a%mod;
		a = (ll)a*a%mod;
		b >>= 1;
	}
	return gg;
}

int f(int n){
	int gg = 1;
	for(int i=2; i<=n; i++)
		if(i%3) gg = (ll)gg*i%27;
	return gg;
}

int C(int n, int m){
	if(m > n) return 0;
	int r = n - m, e0 = 0, eq = 0;
	int cr = r, cm = m, carry = 0, count = 0;
	while(cr || cm || carry){
		count++;
		int rr = cr%3, rm = cm%3;
		if(rr + rm + carry >= 3){
			e0++;
			if(count >= 3) eq++;
		}
		carry = (carry + rr + rm)/3;
		cr /= 3, cm /= 3;
	}
	int mul = pow(-1, eq)*pow(3, e0);
	int gg = (mul%27 + 27)%27;
	for(int temp = 1, maxi = n/3; ; temp *= 3){
		gg = (ll)gg * f(n/temp%27)%27 * exp(f(m/temp%27), 17, 27)%27 * exp(f(r/temp%27), 17, 27)%27;
		if(temp > maxi) break;
	}
	return gg;
}

int Luke(int n, int k, int prime, int A[40][40]){
	int gg = 1;
	while(n){
		gg = gg*A[n%prime][k%prime]%prime;
		n /= prime, k /= prime;
	}
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	for(int i=0; i<40; i++) Co11[i][0] = Co13[i][0] = Co37[i][0] = 1;
	for(int i=1; i<40; i++)
		for(int j=1; j<40; j++){
			Co11[i][j] = (Co11[i-1][j-1] + Co11[i-1][j])%11;
			Co13[i][j] = (Co13[i-1][j-1] + Co13[i-1][j])%13;
			Co37[i][j] = (Co37[i-1][j-1] + Co37[i-1][j])%37;
		}
	int te; scanf("%d", &te);
	while(te--){
		int n, k; scanf("%d %d", &n, &k);
		int a = C(n, k), b = Luke(n, k, 11, Co11), c = Luke(n, k, 13, Co13), d = Luke(n, k, 37, Co37);
		int gg = (137566*a%142857 + 103896*b%142857 + 109890*c%142857 + 77220*d%142857)%142857;
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
