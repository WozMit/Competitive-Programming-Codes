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
		int ind = 0;
		for(int i=0; i<s.size(); i++){
			if(ind == 0 && s[i] == 'h') ind++;
			if(ind == 1 && s[i] == 'e') ind++;
			if((ind == 2 || ind == 3) && s[i] == 'l') ind++;
			if(ind == 4 && s[i] == 'o') ind++;
		}
		if(ind == 5) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}