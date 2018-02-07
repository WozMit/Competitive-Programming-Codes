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
string e = "ABCDEFGHIJKLMNOPRSTUVWXY0123456789", v = "2223334445556667778889990123456789", b, s;

char val(char c){ return v[e.find(c)]; }

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	bool flag = false;
	while(te--){
		if(flag) printf("\n");
		else flag = true;
		int n; scanf("%d", &n);
		vector<string> V(n);
		for(int i=0; i<n; i++){
			s = "";
			cin >> b;
			for(int j=0; j<b.size(); j++)
				if(b[j] != '-') s += val(b[j]);
			V[i] = s.substr(0, 3)+'-'+s.substr(3);
			//db(V[i]);
			//db(V[i].size());
		}
		sort(V.begin(), V.end());
		int count = 0;
		string last = "";
		bool gg = false;
		for(int i=1; i<n; i++){
			if(V[i] == V[i-1]) count++, last = V[i];
			else{
				if(count){
					printf("%s %d\n", last.c_str(), count + 1);
					gg = true;
				}
				count = 0;
			}
		}
		if(count && last != "") printf("%s %d\n", last.c_str(), count + 1);
		else if(!gg) printf("No duplicates.\n");
	}
	//db(val('E'));
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
