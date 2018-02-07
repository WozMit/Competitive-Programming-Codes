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
const int MAX = (int)1e6+5;
int a[MAX];
ll p[MAX], d[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		for(int i=0; i<n; i++){
			ll x; scanf("%lld", &x);
			p[i] = x + (i ? p[i-1]:0ll);
		}
		ll gg = a[0];
		if(n < 4000){
			for(int i=0; i<n; i++)
				for(int j=i+1; j<n; j++){
					gg = max(gg, a[i] + a[j] + (j ? p[j-1]:0ll) - p[i]);
					gg = max(gg, a[j] + a[i] + (i ? p[i-1]:0ll) + p[n-1] - p[j]);
				}
		} else{
			d[0] = a[0] - p[0];
			for(int i=1; i<n; i++) d[i] = max(d[i-1], a[i] - p[i]);
			for(int i=0; i<n; i++){
				gg = max(gg, a[i] + (i ? p[i-1]:0ll) + (i ? d[i-1]:0ll));
				gg = max(gg, a[i] + (i ? p[i-1]:0ll) + p[n-1] + (i < n-1 ? d[i+1]:0ll));
			}
		}
		printf("%lld\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
