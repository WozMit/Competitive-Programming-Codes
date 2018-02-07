//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int x, y, d;

void GCD(int a, int b){
	if(b == 0){
		x = 1;
		y = 0;
		d = a;
	}
	else{
		GCD(b, a%b);
		int x1 = y;
		int y1 = x - (a/b) * y;
		x = x1;
		y = y1;
	}
}

int main() {
	int a, b;
	while(scanf("%d %d", &a, &b) == 2){
		GCD(a, b);
		printf("%d %d %d\n", x, y, d);
	}
	return 0;
}