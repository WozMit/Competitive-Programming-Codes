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

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	char s[105];
	int sum[105];
	while(scanf("%s", &s) == 1){
		int n = strlen(s), gg = 0;
		sum[0] = (s[0] == 'Q');
		for(int i=1; i<n; i++) sum[i] = sum[i-1] + (s[i] == 'Q');
		for(int i=0; i<n; i++)
			if(s[i] == 'A') gg += sum[i]*(sum[n-1] - sum[i]);
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
