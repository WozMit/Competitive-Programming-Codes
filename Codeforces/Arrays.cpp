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
int A[100005], B[100005];

int main() {
	int na, nb, k, m;
	while(cin >> na >> nb >> k >> m){
		for(int i=0; i<na; i++) cin >> A[i];
		for(int i=0; i<nb; i++) cin >> B[i];
		cout << (A[k-1] < B[nb-m] ? "YES":"NO") << endl;
	}
	return 0;
}