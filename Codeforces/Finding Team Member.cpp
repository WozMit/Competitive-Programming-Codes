//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int P[805], M[805][805];

int main() {
	int n;
	while(cin >> n){
		memset(P, 0, sizeof P);
		for(int i=2; i<=2*n; i++)
			for(int j=1; j<i; j++) cin >> M[i][j];
		for(int i = 2*n; i>1; i--){
			if(!P[i]){
				int max = -1, pos = -1;
				for(int j=1; j<i; j++)
					if(!P[j] && M[i][j] > max){
						max = M[i][j];
						pos = j;
					}
				P[i] = pos;
				P[pos] = i;
			}
		}
		for(int i=1; i<=2*n; i++) cout << P[i] << " ";
		cout << endl;
	}
	return 0;
}