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
	int n, m;
	while(scanf("%d %d", &n, &m) == 2){
		int gg = 0, a, b;
		while(n--){
			for(int i=0; i<m; i++){
				scanf("%d %d", &a, &b);
				if(a | b) gg++;
			}
		}
		printf("%d\n", gg);
	}
	return 0;
}