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
	int te, A[25]; scanf("%d", &te);
	while(te--){
		int n, p;
		scanf("%d %d", &n, &p);
		for(int i=0; i<p; i++) scanf("%d", &A[i]);
		bool flag = false;
		for(int m=0; !flag && m<(1<<p); m++){
			int sum = 0;
			for(int i=0; i<p; i++)
				if(m&(1<<i)) sum += A[i];
			if(sum == n) flag = true;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
