//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll f[15];
char A[13], GG[13];
int n = 13;

void Permutation(ll p){
	int loc = 0;
	for(int k=1; k<=n; k++){
		int i = (p+f[n-k]-1)/f[n-k]-1;
		GG[loc++] = A[i];
		p -= f[n-k]*i;
		for(int j=i+1; j<n; j++) A[j-1] = A[j];
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	f[0] = 1;
	for(int i=1; i<14; i++) f[i] = f[i-1]*i;
	int t;
	cin >> t;
	while(t--){
		ll  m;
		cin >> m;
		strcpy(A, "abcdefghijklm");
		Permutation(m);
		cout << GG << "\n";
	}
	#ifdef WozMit
		//printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s";
	#endif
	return 0;
}
