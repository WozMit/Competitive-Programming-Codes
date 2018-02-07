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
	int n;
	while(scanf("%d", &n) == 1){
		int gg = 0, x, y, len, op = 3;
		for(int i=0; i<n; i++){
			scanf("%d", &x);
			if(i == 0) len = 1;
			else{
				if(op == 3){
					if(x > y) op = 1;
					else if(x < y) op = 0;
					len++;
				}
				else if(x != y){

				}
			}
			y = x;
			gg = max(gg, len);
		}
		printf("%d\n", gg);
	}
	return 0;
}