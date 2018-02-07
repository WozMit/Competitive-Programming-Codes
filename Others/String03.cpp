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
	char s[30] = "holaadfasc";
	cout << strlen(s) << endl;
	for(int i=0; i<strlen(s)+2; i++) cout << s[i] << "-";
	cout << endl;
	strcpy(s, "csma");
	cout << strlen(s) << endl;
	puts(s);
	for(int i=0; i<strlen(s)+4; i++) cout << s[i] << "-";
	cout << endl;
	return 0;
}