//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = (int)1e3 + 5;
int rem[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, m;
	while(scanf("%d %d", &n, &m) == 2){
		for(int i=1; i<=m; i++)
			rem[i] = (i * i) % m;
		ll gg = 0L;
		for(int i=1; i<=m; i++)
			for(int j=i; j<=m; j++)
				if((rem[i] + rem[j])%m == 0){
					ll canti = n / m + (i <= n % m ? 1L : 0L);
					ll cantj = n / m + (j <= n % m ? 1L : 0L);
					gg += (i == j ? 1L:2L) * canti * cantj;
				}
		printf("%I64d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
