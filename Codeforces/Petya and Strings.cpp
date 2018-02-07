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
	string a, b, s, t;
	while(cin >> a >> b){
		string s = "", t = "";
		for(int i=0; i<a.size(); i++){
			if(a[i] <= 'Z') s += a[i]+32;
			else s += a[i];
			if(b[i] <= 'Z') t += b[i]+32;
			else t += b[i];
		}
		int cond = 0;
		for(int i=0; i<s.size(); i++){
			if(s[i] > t[i]){
				cond = 1;
				break;
			}
			else if(s[i] < t[i]){
				cond = -1;
				break;
			}
		}
		printf("%d\n", cond);
	}
	return 0;
}