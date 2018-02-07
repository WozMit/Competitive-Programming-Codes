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
	int n;
	string s;
	while(cin >> n >> s){
		int gg = 0;
		for(int i=1; i<s.size(); i++){
			if(s[i] == s[i-1]) gg++;
		}
		printf("%d\n", gg);
	}
	return 0;
}