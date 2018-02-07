//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int main() {
	int n, casE = 0;
	while(scanf("%d", &n) == 1 && n != -1){
		printf("Case %d: %d\n", ++casE, 31-__builtin_clz(n-1));
	}
	return 0;
}