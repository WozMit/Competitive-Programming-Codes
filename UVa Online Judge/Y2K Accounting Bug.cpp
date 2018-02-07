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
int s, d, A[12], gg;

void bt(int curr, int sum){
	if(curr == 12){
		int tot = 0; for(int i=0; i<12; i++) tot += A[i];
		gg = max(gg, tot);
	}
	else{
		if(curr > 4) sum -= A[curr-5];
		A[curr] = s;
		if(curr < 4 || sum+s<0) bt(curr+1, sum + s);
		A[curr] = -d;
		if(curr < 4 || sum-d<0) bt(curr+1, sum - d);
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &s, &d) == 2){
		gg = 0;
		bt(0, 0);
		if(gg > 0) printf("%d\n", gg);
		else printf("Deficit\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
