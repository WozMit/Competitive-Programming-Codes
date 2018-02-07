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
string s;

void Inv(string &t){
	t = "";
	int pos = 0;
	vector<string> V;
	for(int i=1; i<s.size(); i++)
		if(s[i] == ' ' || i == s.size()-1) V.push_back(s.substr(pos, i-pos)), pos = i+1;
	reverse(V.begin(), V.end());
	pos = V.size();
	t += toupper(V[0][0]);
	t += V[0].substr(1, V[0].size()-1);
	if(pos > 1){
		t += " ";
		for(int i=1; i<pos-1; i++) t += V[i]+" ";
		t += tolower(V[pos-1][0]);
		t += V[pos-1].substr(1, V[pos-1].size()-1);
	}
	t += '.';
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t;
	scanf("%d", &t);
	cin.ignore();
	while(t--){
		getline(cin, s);
		string t;
		Inv(t);
		printf("%s\n", t.c_str());
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
