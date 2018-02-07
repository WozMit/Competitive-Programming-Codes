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
	char s[] = "Hello, world. I'm programming in C++...";
	vector<string> tokens;
	for(char *p = strtok(s, " ,."); p; p = strtok(NULL, " ,.")){
		for(int i=0; p[i]; i++) p[i] = toupper(p[i]);
		tokens.push_back(p);
	}
	for(int i=0; i<tokens.size(); i++) printf("%s ", tokens[i].c_str());
	printf("\n");
	return 0;
}