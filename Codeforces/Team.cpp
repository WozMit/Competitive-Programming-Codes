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
	int n, a, b, c;
	while(scanf("%d", &n) == 1){
		int gg = 0;
		while(n--){
			scanf("%d %d %d", &a, &b, &c);
			if(a + b + c > 1) gg++;
		}
		printf("%d\n", gg);
	}
	return 0;
}