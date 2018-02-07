//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <set>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t, n, A[15];
	while(scanf("%d %d", &t, &n) == 2 && n){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		printf("Sums of %d:\n", t);
		bool flag = false;
		set<string> S;
		for(int m=1; m<(1<<n); m++){
			int sum = 0;
			vector<int> V;
			string s = "";
			for(int i=0; i<n; i++)
				if(m&(1<<i)) sum += A[i], V.push_back(A[i]);
			if(sum == t){
				flag = true;
				for(int i=0; i<V.size()-1; i++){
					char num[4];
					sprintf(num, "%d+", V[i]);
					s += num;
				}
				char num[4];
				sprintf(num, "%d", V[V.size()-1]);
				s += num;
				S.insert(s);
			}
		}
		if(S.size()){
			vector<string> V(S.begin(), S.end());
			sort(V.rbegin(), V.rend());
			for(int i=0; i<V.size(); i++) printf("%s\n", V[i].c_str());
		}
		else printf("NONE\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
