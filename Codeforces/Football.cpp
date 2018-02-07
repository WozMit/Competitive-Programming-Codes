//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s;
	while(cin >> s){
		bool flag = false;
		char c = s[0];
		int cant = 0;
		for(int i=0; i<s.size() && !flag; i++){
			if(s[i] == c) cant++;
			else{
				cant = 1;
				c = s[i];
			}
			if(cant == 7) flag = true;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}