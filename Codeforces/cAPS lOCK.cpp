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
	string s, p;
	cin >> s;
	p = "";
	bool flag = true;
	for(int i=1; i<s.size(); i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			flag = false;
			break;
		}
	}
	if(flag == false) p = s;
	else{
		for(int i=0; i<s.size(); i++){
			if(s[i] >= 'a' && s[i] <= 'z')
				p += char(int(s[i])-32);
			else
				p += char(int(s[i])+32);
		}
	}
	cout << p << endl;
	return 0;
}