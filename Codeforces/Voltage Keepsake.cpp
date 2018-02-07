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
int n, p, a[MAX], b[MAX];

bool Can(double t){
	double sum = 0.0;
	for(int i=0; i<n; i++){
		sum += max(0.0, t*a[i] - b[i]);
		if(sum > t*p) return false;
	}
	return true;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &n, &p) == 2){
		for(int i=0; i<n; i++) scanf("%d %d", &a[i], &b[i]);
		ll sum = 0ll;
		for(int i=0; i<n; i++) sum += a[i];
		if(p >= sum) puts("-1");
		else{
			double i = 0.0, j = 1e14+5;
			int k = 100;
			while(k--){
				double mid = (i+j)/2.0;
				if(Can(mid)) i = mid;
				else j = mid;
			}
			printf("%.14f\n", i);
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
