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
	int a1, a2, a3, b1, b2, b3, n;
	while(scanf("%d %d %d %d %d %d %d", &a1, &a2, &a3, &b1, &b2, &b3, &n) == 7){
		double a = a1 + a2 + a3;
		double b = b1 + b2 + b3;
		if(ceil(a/5.0) + ceil(b/10) > n) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}