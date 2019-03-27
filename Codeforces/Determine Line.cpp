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

vector<int> intersection(vector<int> &v1, vector<int> &v2){
    vector<int> v3;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));
    return v3;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1){
		set<int> S;
		vector<int> v1;
		int r; scanf("%d", &r);
		while(r--){
			int x; scanf("%d", &x);
			v1.push_back(x);
		}
		sort(v1.begin(), v1.end());
		for(int i=0; i<n-1; i++){
			scanf("%d", &r);
			vector<int> v2;
			while(r--){
				int x; scanf("%d", &x);
				v2.push_back(x);
			}
			v1 = intersection(v1, v2);
		}
		for(int e : v1) printf("%d ", e);
		printf("\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
