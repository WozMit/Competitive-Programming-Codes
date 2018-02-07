//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n"
using namespace std;
const int MAX = 10007;
int v[MAX], cy[MAX], gg[MAX];

int cycle(int den){
	memset(v, 0, sizeof v);
	int num = 1;
	for(int i=1; num; i++){
		if(v[num]) return i-v[num];
		v[num] = i;
		num = (num*10)%den;
	}
	return 0;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	for(int i=2; i<MAX; i++) cy[i] = cycle(i);
	for(int i=3; i<MAX; i++)
		gg[i] = cy[i]>cy[gg[i-1]] ? i:gg[i-1];
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", gg[n-1]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s";
	#endif
	return 0;
}
