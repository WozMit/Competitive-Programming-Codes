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
const int MAX = (int)1e6+5;
int phi[MAX];
ll sum[MAX];

void PreProcess(){
	for(int i=1; i<MAX; i++){
		phi[i] = i;
		sum[i] = 0ll;
	}
	for(int i=2; i<MAX; i++)
		if(phi[i] == i){
			phi[i]--;
			for(int j=i+i; j<MAX; j+=i)
				phi[j] -= phi[j] / i;
		}
	for(int i=1; i<MAX; i++)
		for(int j=i+i; j<MAX; j+=i)
			sum[j] += i * phi[j / i];
	for(int i=3; i<MAX; i++)
		sum[i] += sum[i - 1];
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	PreProcess();
	int n;
	while(scanf("%d", &n) == 1 && n){
		printf("%lld\n", sum[n]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
