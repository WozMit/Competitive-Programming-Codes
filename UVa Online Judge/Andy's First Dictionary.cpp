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
	string s;
	set<string> S;
	while(cin >> s){
        int size = s.size();
        string current = "";
        for (int i = 0; i < size; i++){
            char c = tolower(s[i]);
            if (c >= 'a' && c <= 'z') current += c;
            else if (current != ""){
                S.insert(current);
                current = "";
            }
        }
		if (current != "") S.insert(current);
	}
	for(set<string>::iterator i=S.begin(); i!=S.end(); i++)
		if((*i) != "")printf("%s\n", (*i).c_str());
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
