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
#define db(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te;
	scanf("%d", &te);
	while(te--){
		string S, t;
		cin >> S;
		sort(S.begin(), S.end());
		int k;
		scanf("%d", &k);
		bool f1 = true;
		set<char> G;
		while(k--){
			cin >> t;
			sort(t.begin(), t.end());
			bool take = true;
			for(int i=0; i<S.size(), S[i]<='Z'; i++)
				if(!binary_search(t.begin(), t.end(), S[i])) take = false;
			if(take){
				string T = "";
				for(int i=0; i<t.size(), t[i]<='Z'; i++)
					if(!binary_search(S.begin(), S.end(), t[i])) T += t[i];
				if(f1){
					f1 = false;
					for(int i=0; i<T.size(); i++) G.insert(T[i]);
				}
				else{
					vector<char> Del;
					for(set<char>::iterator i = G.begin(); i!=G.end(); i++)
						if(!binary_search(T.begin(), T.end(), *i)) Del.push_back(*i);
					for(int i=0; i<Del.size(); i++) G.erase(Del[i]);
				}
			}
		}
		if(G.empty()) printf("No Solution\n");
		else{
			set<char>::iterator gg = G.begin();
			printf("%c\n", *gg);
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
	#endif
	return 0;
}
