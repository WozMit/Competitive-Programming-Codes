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
	char str[] = "Hola mundo!!!mundo";
	char * pt = strstr(str, "mundo");
	int pos = 0;
	while(pt != NULL){
		strncpy(pt, pt, sizeof "mundo");
		cout << pt << endl;
		pt = strstr(str+pos, "mundo");
		pos++;
	}
	return 0;
}