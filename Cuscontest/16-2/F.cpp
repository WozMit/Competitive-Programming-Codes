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
	int n;
	scanf("%d", &n);
	multiset<string> S;
	while(n--){
		string name, email;
		cin >> name >> email;
		if(email.substr(email.size()-10, 10) == "@gmail.com") S.insert(name);
	}
	for(multiset<string>::iterator i = S.begin(); i!=S.end(); i++)
			printf("%s\n", (*i).c_str());
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
