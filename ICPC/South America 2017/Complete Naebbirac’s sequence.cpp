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
const int MAX = (int)1e4+5;

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int k, n, A[MAX], frec[MAX];
	while(scanf("%d %d", &k, &n) == 2){
		for(int i=1; i<=k; i++) frec[i] = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &A[i]);
			frec[A[i]]++;
		}
		int x = 1, y = 1, mini_frec = 0, maxi_frec = 0;
		for(int i=1; i<=k; i++){
			if(frec[i] < frec[x]) x = i;
			if(frec[i] > frec[y]) y = i;
		}
		for(int i=1; i<=k; i++){
			if(frec[i] == frec[x]) mini_frec++;
			if(frec[i] == frec[y]) maxi_frec++;
		}
		if(mini_frec == 1 && maxi_frec*frec[y] == n-frec[x] && frec[x]+1 == frec[y])
			printf("+%d\n", x);
		else if(maxi_frec == 1 && mini_frec*frec[x] == n-frec[y] && frec[y]-1 == frec[x])
			printf("-%d\n", y);
		else if(mini_frec == 1 && maxi_frec == 1 && frec[x]+1 == frec[y]-1) printf("-%d +%d\n", y, x);
		else puts("*");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
