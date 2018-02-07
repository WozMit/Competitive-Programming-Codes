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
	int n, m, A[101];
	while(cin >> n >> m){
		int gg1 = -1, gg2;
		for(int i=0; i<=n; i++) A[i] = 0;
		while(m--){
			int max = -1, index, temp;
			for(int i=0; i<n; i++){
				cin >> temp;
				if(temp > max){
					max = temp;
					index = i+1;
				}
			}
			A[index]++;
		}
		for(int i=0; i<=n; i++){
			if(A[i] > gg1){
				gg1 = A[i];
				gg2 = i;
			}
		}
		cout << gg2 << endl;
	}
	return 0;
}