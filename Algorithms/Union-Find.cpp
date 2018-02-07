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
const int MAX = (int)1e6+5;
int p[MAX], ran[MAX], cG;

int Find(int x){
	if(x == p[x]) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy){
		if(ran[fx] > ran[fy]) p[fy] = fx;
		else{
			p[fx] = fy;
			if(ran[fx] == ran[fy]) ran[fy]++;
		}
		cG--;
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		cG = n;
		for(int i=0; i<n; i++) p[i] = i, ran[i] = 0;
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
