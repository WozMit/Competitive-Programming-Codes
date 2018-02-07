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
	int n;
	while(scanf("%d", &n) == 1){
		int gg = 0, tram = 0, a, b;
		while(n--){
			scanf("%d %d", &a, &b);
			tram += b-a;
			gg = max(gg, tram);
		}
		printf("%d\n", gg);
	}
	return 0;
}