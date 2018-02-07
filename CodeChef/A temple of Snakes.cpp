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
const int MAX = (int)1e5+5;
int A[MAX], n;

bool Check(int x){
	for(int i=0, current = 1, sgn = 1; i<n; i++){
		if(current <= A[i]){
			if(current == x) sgn = -1;
			current += sgn;
			if(!current) return true;
		}
		else current = A[i] + 1, sgn = 1;
	}
	return false;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		scanf("%d", &n);
		ll sum = 0ll;
		for(int i=0; i<n; i++) scanf("%d", &A[i]), sum += A[i];
		int i = 1, j = (n+3)/2;
		while(j - i > 1){
			int mid = i + (j - i)/2;
			if(Check(mid)) i = mid;
			else j = mid;
		}
		printf("%lld\n", sum - (ll)i*i);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
