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

int v(string s){
	int gg = 0;
	for(int i=0; i<s.size(); i++) gg += s[i]-64;
	return gg;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, q;
	cin >> n;
	vector<string> A(n);
	for(int i=0; i<n; i++) cin >> A[i];
	sort(A.begin(), A.end());
	cin >> q;
	while(q--){
		string s;
		cin >> s;
		cout << v(s)*(lower_bound(A.begin(), A.end(), s)-A.begin()+1) << "\n";
	}
	#ifdef WozMit
		//printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s";
	#endif
	return 0;
}
