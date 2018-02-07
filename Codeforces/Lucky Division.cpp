//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int D[] = {4, 7, 44, 77, 444, 47, 74, 447, 474, 477};

int main() {
	int n;
	while(scanf("%d", &n) == 1){
		bool flag = true;
		for(int i=0; flag && i<10; i++)
			if(n%D[i] == 0) flag = false;
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}