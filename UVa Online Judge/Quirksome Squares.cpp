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
int n, mid;

bool Magic(int x){
	int a = 0, b = x*x, pot = 0;
	for(int i=0; i<mid; i++){
		a += (b%10)*pow(10, pot++);
		b /= 10;
	}
	return a+b == x;
}

int main() {
	while(scanf("%d", &n) == 1){
		mid = n>>1;
		int lim = pow(10, mid);
		for(int i=0; i<lim; i++)
			if(Magic(i))
				switch(n){
					case 2: printf("%02d\n", i*i); break;
					case 4: printf("%04d\n", i*i); break;
					case 6: printf("%06d\n", i*i); break;
					case 8: printf("%08d\n", i*i); break;
				}
	}
	return 0;
}