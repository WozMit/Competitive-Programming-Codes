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

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, l;
	while(scanf("%d %d", &n, &l) == 2){
		vector<int> N;
		int x;
		for(int i=0; i<n; i++){
			scanf("%d", &x);
			N.push_back(x);
		}
		sort(N.begin(), N.end());
		int gg = 0;
		for(int i=1; i<l; i++){
			bool flag = true;
			for(int j=0; flag && N[j]<i; j++)
				if(l-i>=i-N[j] && !binary_search(N.begin(), N.end(), i+i-N[j]))
					flag = false;
			for(int j=N.size()-1; flag && N[j]>i; j--)
				if(i>=N[j]-i && !binary_search(N.begin(), N.end(), i-(N[j]-i)))
					flag = false;
			if(flag) gg++;
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
