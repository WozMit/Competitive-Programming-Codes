//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

bool Beautiful(string s){
	bool one = false;
	for(int i=0; i<s.size(); i++){
		if(s[i] != '0' && s[i] != '1') return false;
		if(s[i] == '1'){
			if(one) return false;
			one = true;
		}
	}
	return true;
}

int main() {
	int n;
	while(scanf("%d", &n) == 1){
		int zeros = 0;
		string s, lead = "1";
		bool flag1 = false, flag2 = true;
		while(n--){
			cin >> s;
			if(s == "0") flag2 = false;
			if(flag2){
				if(flag1 || Beautiful(s)) zeros += s.size()-1;
				else{
					lead = s;
					flag1 = true;
				}
			}
		}
		if(!flag2) cout << 0 << endl;
		else{
			cout << lead;
			while(zeros--) cout << 0;
			cout << endl;
		}
	}
	return 0;
}