//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int base = (int)1e9;

struct Int{
	vector<int> a;
	bool sgn;
	Int(){sgn = false, a.push_back(0); }
	Int(string s){
		if(s[0] == '-') sgn = true, s[0] = '0';
		else sgn = false;
		for(int i=(int)s.size(); i>0; i-=9)
			a.push_back(atoi( (i < 9 ? s.substr(0, i):s.substr(i-9, 9)).c_str() ));
		while(a.size() > 1 && a.back() == 0) a.pop_back();
	}
	void print(){
		if(sgn && !a.empty()) printf("-");
		printf("%d", (a.empty() ? 0:a.back()));
		for(int i=(int)a.size()-2; i>=0; i--) printf("%09d", a[i]);
		printf("\n");
	}
};

int cmp(Int &a, Int &b){
	if(a.sgn && !b.sgn) return -1;
	if(!a.sgn && b.sgn) return 1;
	int as = a.a.size(), bs = b.a.size();
	if(as > bs) return (a.sgn ? -1:1);
	if(as < bs) return (a.sgn ? 1:-1);
	for(int i=as-1; i>=0; i--){
		if(a.a[i] > b.a[i]) return (a.sgn ? -1:1);
		if(a.a[i] < b.a[i]) return (a.sgn ? 1:-1);
	}
	return 0;
}

/*void sub(Int &a, Int &b){
	int carry = 0;
	for(size_t i=0; carry || i<b.a.size(); i++){
		a.a[i] -= carry + (i < b.a.size() ? b.a[i]:0);
		carry = a.a[i] < 0;
		if(carry) a.a[i] += base;
	}
	while(a.a.size() > 1 && a.a.back() == 0) a.a.pop_back();
}*/

Int add(Int &a, Int &b){
	int carry = 0, cs = a.a.size(), bs = b.a.size(), maxi = max(cs, bs);
	Int c = Int();
	c.a = a.a;
	c.sgn = a.sgn;
	for(size_t i=0; carry || i<maxi; i++){
		if(i == cs) c.a.push_back(0), cs++;
		c.a[i] += carry + (i < bs ? b.a[i]:0);
		carry = c.a[i] >= base;
		if(carry) c.a[i] -= base;
	}
	return c;
}

Int sub(Int &a, Int &b){
	if(a.sgn == b.sgn) return add(a, b);
	Int c = Int();
	int carry = 0;
	for(size_t i=0; carry || i<b.a.size(); i++){
		a.a[i] -= carry + (i < b.a.size() ? b.a[i]:0);
		carry = a.a[i] < 0;
		if(carry) a.a[i] += base;
	}
	while(a.a.size() > 1 && a.a.back() == 0) a.a.pop_back();
	return c;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	string s, t;
	while(cin >> s >> t){
		Int a = Int(s), b = Int(t);
		db("//////");
		a.print();
		b.print();
		sub(a, b).print();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
