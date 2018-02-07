//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <time.h>
#include <bitset>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = (int)1e7+5;
int power10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int digits, k, len, number, prime[MAX], miniPrime;
char numb[10];
map<string, vector<int> > M;

void Sieve(int n){
	for(int i=2; i<n; i++) prime[i] = i&1 ? i:2;
	for(int i=3; i*i<n; i+=2)
		if(prime[i] == i) for(int j=i*i; j<n; j+=2*i) prime[j] = i;
}

void Match(char dig, int howOften, int stPos = 0){
	for(int i=stPos; i<digits; i++){
		if(numb[i] != dig || (!i && dig == '0')) continue;
		numb[i] = '.';
		if(howOften == 1){
			vector<int> V = M[string(numb)];
			V.push_back(number);
			if(V.size() >= len && V.front() < miniPrime)
				miniPrime = V.front();
			M[string(numb)] = V;
		} else Match(dig, howOften-1, i+1);
		numb[i] = dig;
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d %d", &digits, &k, &len) == 3){
		int mini = power10[digits-1], maxi = power10[digits]-1;
		//cout << digits << " " << k << " " << len << "\n";
		Sieve(maxi+5);
		miniPrime = power10[8];
		for(int i=mini; i<=maxi; i++)
			if(prime[i] == i){
				number = i;
				sprintf(numb, "%d", i);
				for(char j='0'; j<='9'; j++) Match(j, k);
				if(digits == 7 && ((k == 1 && i > 2000000)||(k == 2 && i > 3000000))) break;
			}
		string gg = "";
		for(map<string, vector<int> >::iterator j=M.begin(); j!=M.end(); j++){
			vector<int> V = (*j).second;
			if(V.size() < len || V.front() != miniPrime) continue;
			string s = "";
			for(int i=0; i<len; i++){
				char x[10];
				sprintf(x, "%d ", V[i]);
				s += string(x);
			}
			if(s < gg || gg == "") gg = s;
		}
		printf("%s\n", gg.c_str());
		M.clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
