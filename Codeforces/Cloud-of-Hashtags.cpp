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
const int MAX = 500005;
int n;
string T[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	scanf("%d", &n);
	for(int i=0; i<n; i++) cin >> T[i];
	if(n > 2){
		for(int i=n-1; i>0; i--){
			int p = -1; bool flag = true;
			for(int j=0; flag && j<max(T[i].size(), T[i-1].size()); j++){
				if(T[i][j] > T[i-1][j]) flag = false;
				else if(T[i][j] < T[i-1][j]){
					p = j;
					break;
				}
			}
			if(flag) T[i-1] = T[i-1].substr(0, p);
		}
	}
	for(int i=0; i<n; i++){
		if(T[i] == "") while(1) 3;
		printf("%s\n", T[i].c_str());
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
