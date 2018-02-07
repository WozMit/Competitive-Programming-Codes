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
	int a, b, c, x, y , z;
	while(scanf("%d %d %d %d %d %d", &a, &b, &c, &x, &y, &z) == 6){
		x = a - x;
		y = b - y;
		z = c - z;
		if(x > 0) x /= 2;
		if(y > 0) y /= 2;
		if(z > 0) z /= 2;
		if(x + y + z >= 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}