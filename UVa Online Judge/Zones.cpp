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
int T[25], C[15];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te = 0, n, m, c;
	while(scanf("%d %d", &n, &m) == 2 && n && m){
		printf("Case Number  %d\n", ++te);
		for(int i=0; i<n; i++) scanf("%d", &T[i]);
		vector<pair<int, int> > V;
		scanf("%d", &c);
		for(int i=0; i<c; i++){
			int num, x, inter = 0, val; scanf("%d", &num);
			while(num--){
				scanf("%d", &x);
				inter |= 1<<(x-1);
			}
			scanf("%d", &val);
			V.push_back(make_pair(inter, val));
		}
		int gg = 0;
		vector<int> GG;
		for(int i=1; i<(1<<n); i++)
			if(__builtin_popcount(i) == m){
				int sum = 0;
				for(int j=0; j<n; j++) if(i&(1<<j)) sum += T[j];
				for(int j=0; j<c; j++)
					if(i&V[j].first) sum -= (__builtin_popcount(i&V[j].first)-1)*V[j].second;
				vector<int> V1;
				for(int j=0; j<n; j++) if(i&(1<<j)) V1.push_back(j+1);
				sort(V1.begin(), V1.end());
				if(sum > gg ||(sum == gg && V1.size() && GG.size() && V1[0] < GG[0]))
					gg = sum, GG = V1;
			}
		printf("Number of Customers: %d\nLocations recommended: ", gg);
		for(int i=0; i<GG.size(); i++){
			printf("%d", GG[i]);
			if(i < GG.size()-1) printf(" ");
		}
		printf("\n\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
