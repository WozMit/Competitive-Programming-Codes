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
const int MAX = (int)1e5+5;

bool isvowel(char c){ return c=='a' || c=='e' || c=='i' || c=='o' || c == 'u'; }

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	char s[MAX];
	while(scanf("%s", &s) == 1){
		int n = strlen(s), vowels = 0;
		for(int i=0; i<n; i++) vowels += isvowel(s[i]);
		int i = 0, j = n - 1, gg = 0;
		while(true){
			int minus = i < j ? 1:-1;
			if(!isvowel(s[i]) || i == j){
				if(!vowels || i == j) gg++;
				break;
			}
			if(isvowel(s[j])){
				swap(i, j);
				j += minus;
				vowels--;
			}
			else{
				if(vowels == 1) gg++;
				j -= minus;
			}
		}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
