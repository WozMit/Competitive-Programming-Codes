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
		if(s[0] >= 'a' && s[0] <= 'z'){
			cout << char(int(s[0])-32);
			cout << s.substr(1, s.size()-1) << endl;
		}
		else cout << s << endl;
	}
	return 0;
}