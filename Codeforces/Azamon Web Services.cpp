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

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		string a, b; cin >> a >> b;
		//db(a);
		//db(b);
		if(a == b){
			string t = a;
			sort(t.begin(), t.end());
			if(a == t) printf("---\n");
			else{
			for(int i=0; i<a.size(); i++){
				if(a[i] > t[i]){
					int besty = i;
					for(int j=i+1; j<a.size(); j++)
						if(a[j] < a[besty])
							besty = j;
					swap(a[i], a[besty]);
					printf("%s\n", a.c_str());
					break;
				}
			}
			}
		} else{
		bool flag = false;
		if(a < b) flag = true;
		int len = min(a.size(), b.size());
		for(int i=0; i<len; i++)
			if(a[i] > b[i]){
				int mini = i;
				for(int j=i+1; !flag && j<a.size(); j++){
					if(a[j] < a[mini]) mini = j;
					if(a[mini] < b[i]){
						swap(a[i], a[j]);
						flag = true;
					}
				}
				if(!flag && mini != i){
					swap(a[i], a[mini]);
					if(a < b) flag = true;
				}
				break;
			}
		if(flag) printf("%s\n", a.c_str());
		else printf("---\n");
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
