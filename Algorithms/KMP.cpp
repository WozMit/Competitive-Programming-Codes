//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
const int MAX_VAL = 1000;
int S[MAX_VAL];

void KMP(string T, string p){
	int j = 0;
	S[0] = 0;
	for(int i=1; i<p.size(); i++){
		while(j && p[i] != p[j]) j = S[j-1];
		S[i] = p[i] == p[j] ? (j++)+1:0;
	}
	cout << "\"" << p;
	j = 0;
	bool found = false;
	for(int i=0; !found && i<T.size(); i++){
		while(j && T[i] != p[j]) j = S[j-1];
		if(T[i] == p[j]) j++;
		if(j == p.size()){
			cout << "\" found in (" << i-j+1 << ", " << i << ")." << endl;
			found = true;
		}
	}
	if(!found) cout << "\" not found!" << endl;
}

int main() {
	string T, p;
	while(cin >> T){
		cout << "T: \"" << T << "\"" << endl;
		int q;
		cin >> q;
		while(q--){
			cin >> p;
			KMP(T, p);
		}
		cout << endl;
	}
	return 0;
}

/*INPUT:
holamama
3
mama
lamo
amama

abcxabcdabxabcdabcdabcy
1
abcdabcy
*/