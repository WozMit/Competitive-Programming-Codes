//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <map>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	bool flag = false;
	int te; scanf("%d", &te);
	while(te--){
		if(flag) printf("\n");
		else flag = true;
		map<string, pair<int, int> > M;
		string s;
		int n, a, b; scanf("%d", &n);
		while(n--){
			cin >> s;
			scanf("%d %d", &a, &b);
			M[s] = make_pair(a, b);
		}
		scanf("%d", &n);
		while(n--){
			scanf("%d", &a);
			s = "";
			for(map<string, pair<int, int> >::iterator i=M.begin(); i!=M.end(); i++){
				if(a >= i->second.first && a <= i->second.second){
					if(s != ""){
						s = "";
						break;
					}
					else s = i->first;
				}
			}
			if(s == "") printf("UNDETERMINED\n");
			else printf("%s\n", s.c_str());
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
