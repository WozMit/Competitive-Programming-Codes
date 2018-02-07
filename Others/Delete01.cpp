//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
	int n = 3, m = 7;
	double k = 1.234378;
	char s[0], *c, gg[] = "";
	sprintf(s, "%0*.*f", m, n, k);
	puts(s);
	c = strtok(s, ".");
	while(c){
		strcat(gg, c);
		c = strtok(NULL, ".");
	}
	puts(gg);
	int number;
	sscanf(gg, "%d", &number);
	printf("%d", number-1);
	return 0;
}