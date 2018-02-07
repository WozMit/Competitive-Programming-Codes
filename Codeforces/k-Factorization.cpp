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

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, k;
	while(scanf("%d %d", &n, &k) == 2){
		vector<int> V;
		int f = 2, count = 0;
		while(count < k && f*f < n){
			while(count < k && n%f == 0){
				n /= f;
				V.push_back(f);
				count ++;
			}
			f++;
		}
		if(n > 1) V.push_back(n), count++;
		if(count < k) printf("-1\n");
		else{
			for(int i=0; i<k-1; i++) printf("%d ", V[i]);
			ll last = 1ll;
			for(int i=k-1; i<V.size(); i++) last *= V[i];
			if(last > 1ll) cout << last;
			printf("\n");
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
