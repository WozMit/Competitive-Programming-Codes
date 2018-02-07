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

int idx(string s){
	for(int i=s.size()-1; i>=0; i--)
		if(s[i] == '*') return i+1;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	string s;
	int F[30], maxi = 0;
	memset(F, 0, sizeof F);
	for(int i=0; i<4; i++){
		getline(cin, s);
		for(int i=0; i<s.size(); i++)
			if(s[i] >= 'A' && s[i] <= 'Z') maxi = max(maxi, ++F[s[i]-65]);
	}
	for(; maxi; maxi--){
		string gg = "";
		for(int i=0; i<26; i++)
			if(F[i] == maxi) gg += "* ", F[i]--;
			else gg += "  ";
		cout << gg.substr(0, idx(gg)) << "\n";
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
