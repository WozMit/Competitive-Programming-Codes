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
	int n;
	while(scanf("%d", &n) == 1){
		string s;
		vector<pair<int, int> > V1, V3;
		for(int i=0; i<n; i++){
			cin >> s;
			for(int j=0; j<n; j++){
				if(s[j] == '1') V1.push_back(make_pair(i, j));
				else if(s[j] == '3') V3.push_back(make_pair(i, j));
			}
		}
		int gg = 0;
		for(int i=0; i<V1.size(); i++){
			int mini = 1<<30;
			for(int j=0; j<V3.size(); j++)
				mini = min(mini, abs(V3[j].first-V1[i].first)+abs(V3[j].second-V1[i].second));
			gg = max(gg, mini);
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
