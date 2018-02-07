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
typedef long long int ll;
string t0[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string t1[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string t2[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string t3[] = {"Hundred", "Thousand", "Million", "Billion", "Trillion"};

string l2(ll n){
	if(n < 10) return t0[n];
	if(n < 20) return t1[n-10];
	int d = n/10ll, u = n%10ll;
	return t2[d]+(u ? " "+t0[u]:"");
}

string l3(ll n){
	if(n < 100) return l2(n);
	int c = n/100ll, ld3 = n%100ll;
	return t0[c]+" "+t3[0]+(ld3 ? " "+l2(ld3):"");
}

string ln(ll n){
	string gg = t0[0];
	int g = 0;
	vector<string> V;
	for(; n; g++){
		ll n1 = n%1000;
		n /= 1000;
		if(n1) V.push_back(g ? l3(n1)+" "+t3[g]:l3(n1));
		string s = "";
		for(int i=0; i<V.size(); i++){
			if(i) s += " ";
			s += V[V.size()-1-i];
		}
		gg = s;
	}
	return gg;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << ln(n) << "\n";
	}
	#ifdef WozMit
		//printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		cout<<string(31,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s";
	#endif
	return 0;
}
