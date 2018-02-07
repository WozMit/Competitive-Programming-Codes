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
const int MAX = (int)3e5+5;
int A[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, q;
	while(scanf("%d %d", &n, &q) == 2){
		set<int> S;
		for(int i=0; i<n; i++){
			S.insert(i);
			A[i] = 0;
		}
		while(q--){
			int l, r, x; scanf("%d %d %d", &l, &r, &x);
			l--; r--; x--;
			vector<int> deleteThis;
			for(set<int>::iterator i=S.lower_bound(l); i!=S.end(); i++){
				int num = *i;
				if(num > r) break;
				if(num != x){
					A[num] = x + 1;
					deleteThis.push_back(num);
				}
			}
			for(int i=0; i<deleteThis.size(); i++) S.erase(deleteThis[i]);
		}
		for(int i=0; i<n; i++) printf("%d ", A[i]);
		printf("\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
