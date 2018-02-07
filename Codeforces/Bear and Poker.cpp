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
	int n, A[200005];
	while(cin >> n){
		int gcd;
		for(int i=0; i<n; i++){
			cin >> A[i];
			gcd = i ? __gcd(gcd, A[i]):A[i];
		}
		bool flag = gcd == 1 ? false:true;
		for(int i=0; i<n && flag; i++){
			int x = A[i]/gcd;
			if(x&1 && x%3 != 0 && x != 1) flag = false;
		}
		cout << (flag ? "Yes":"No") << endl;
	}
	return 0;
}