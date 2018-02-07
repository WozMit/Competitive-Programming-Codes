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
	int t, q, s;
	while(cin >> t >> s >> q){
		int gg = 0;
		while(s < t){
			gg++;
			s *= q;
		}
		cout << gg << endl;
	}
	return 0;
}