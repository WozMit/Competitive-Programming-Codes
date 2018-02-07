    //
    //	Dear maintainer:
    // 
    // Once you are done trying to 'optimize' this routine,
    // and have realized what a terrible mistake that was,
    // please increment the following counter as a warning
    // to the next guy:
    // 
    // total_hours_wasted_here = 0
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
/*int n, p[] = {2, 3, 5, 7, 11, 13, 17, 19}, pw10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

bool Check(ll x){
	for(int i=2; i+1<n; i++)
		if(((x/pw10[n-i-2])%1000)%p[i-2] != 0) return false;
	return true;
}

ll Generate_sum(){
	n++;
	ll gg = 0ll;
	int A[n];
	for(int i=0; i<n; i++) A[i] = i;
	do{
		ll x = A[0];
		for(int i=1; i<n; i++) x = x*10+A[i];
		if(Check(x)) gg += x;
	}while(next_permutation(A, A+n));
	return gg;
}*/

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	/*for(int i=3; i<10; i++){
		n = i;
		cout << Generate_sum() << ", ";
	}*/
	ll GG[] = {22212, 711104, 12444480, 189838560, 1099210170, 1113342912, 16695334890};
	int n;
	while(scanf("%d", &n) == 1) printf("%lld\n", GG[n-3]);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
