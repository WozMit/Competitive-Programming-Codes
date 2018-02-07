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
	int n;
	while(scanf("%d", &n) == 1){
		char c;
		stack<char> P;
		while(n--){
			scanf(" %c", &c);
			if(!P.empty()){
				if(P.top() != c) P.pop();
				else P.push(c);
			}
			else P.push(c);
		}
		printf("%d\n", P.size());
	}
	return 0;
}