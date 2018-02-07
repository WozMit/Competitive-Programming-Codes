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

/*bool Is_trian(ll n){
	double d = (sqrt(8ll*n+1)-1)/2;
	return d == (ll)d;
}

bool Is_hex(ll n){
	double d = (sqrt(8ll*n+1)+1)/4;
	return d == (ll)d;
}*/

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int a, b;
	ll n;
	// OEIS ->
	ll GG3[] = {1ll, 210ll, 40755ll, 7906276ll, 1533776805ll, 297544793910ll, 57722156241751ll, 11197800766105800ll, 2172315626468283465ll};
	ll GG5[] = {1ll, 40755ll, 1533776805ll, 57722156241751ll, 2172315626468283465ll};
	/*ll c = 1, n = 200000000000000;
	for(int i=1; c<n; i++){
		c = i*(3ll*i-1ll)/2ll;
		if(a == 3 && Is_trian(c)) cout << c << ", ";
		else if(Is_hex(c)) cout << c << ", ";
	}
	cout << endl;*/
	while(scanf("%lld %d %d", &n, &a, &b) == 3){
		if(a == 3) for(int i=0; GG3[i] < n; i++) printf("%lld\n", GG3[i]);
		else for(int i=0; GG5[i] < n; i++) printf("%lld\n", GG5[i]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
