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
	int m, n;
	while(scanf("%d %d", &m, &n) == 2)
		printf("%d\n", (m*n)>>1);
	return 0;
}