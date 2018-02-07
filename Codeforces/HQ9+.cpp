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
	cin >> s;
	for(int i=0; i<s.size(); i++){
		if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
			cout << "YES" << endl;
			break;
		}
		if(i == s.size()-1) cout << "NO" << endl;
	}
	return 0;
}