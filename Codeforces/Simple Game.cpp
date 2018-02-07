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
	int n, m;
	while(cin >> n >> m)
		if(n == 1) cout << 1 << endl;
		else cout << (n-m > m-1 ? m+1:m-1) << endl;
	return 0;
}