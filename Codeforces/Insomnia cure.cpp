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
	int a, b, c, d, n;
	while(scanf("%d %d %d %d %d", &a, &b, &c, &d, &n) == 5){
		int gg = 0;
		for(int i=1; i<=n; i++)
			if(i%a && i%b && i%c && i%d) gg++;
		printf("%d\n", n-gg);
	}
	return 0;
}