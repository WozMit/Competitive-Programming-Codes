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
	string s;
	while(cin >> s){
		vector<int> B, F;
		for(int i=0; i<s.size()-1; i++)
			if(s[i] == '(' && s[i+1] == '(') B.push_back(i);
			else if(s[i] == ')' && s[i+1] == ')') F.push_back(i);
		int gg = 0;
		for(int i=0; i<B.size(); i++)
			gg += F.size()-(lower_bound(F.begin(), F.end(), B[i])-F.begin());
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
