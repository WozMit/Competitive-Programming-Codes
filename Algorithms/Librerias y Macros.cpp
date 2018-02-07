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
	int A[6] = {6,5,4,3,2,1};
	sort(A, A+6, condition);
	for(int i=0; i<6; i++) cout << A[i] << " ";
	cout << endl;
	return 0;
}