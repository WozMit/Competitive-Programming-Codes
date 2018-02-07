//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
const int MAX = 5007;
int gg[MAX];

void add(vector<int> &a, vector<int> &b){
	int carry = 0, i = 0;
	for(; i<b.size(); i++){
		if(i == a.size()) a.push_back(0);
		a[i] += b[i]+carry;
		carry = a[i]/10;
		a[i] %= 10;
	}
	while(carry){
		if(i == a.size()) a.push_back(0);
		a[i] += carry;
		carry = a[i]/10;
		a[i] %= 10;
		i++;
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	vector<int> a(1, 1), b(1, 1);
	int index = 2;
	while(true){
		int len = b.size();
		if(len >= MAX) break;
		if(!gg[len]) gg[len] = index-1;
		add(b, a);
		a.swap(b);
		index++;
	}
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << gg[n] << "\n";
	}
	#ifdef WozMit
		//printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s";
	#endif
	return 0;
}
