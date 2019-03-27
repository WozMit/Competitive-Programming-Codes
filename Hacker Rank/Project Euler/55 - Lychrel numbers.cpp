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
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = (int)1e5+5;
ll conv[MAX];
// 116 numbers that converge to 4668731596684224866951378664
int big[] = {10677, 10833, 10911, 11667, 11823, 11901, 12657, 12813, 13647, 13803, 14637, 15627, 16617, 17607, 20676, 20832, 20910, 21666, 21822, 21900, 22656, 22812, 23646, 23802, 24636, 25626, 26616, 27606, 30675, 30831, 31665, 31821, 32655, 32811, 33645, 33801, 34635, 35625, 36615, 37605, 40674, 40830, 41664, 41820, 42654, 42810, 43644, 43800, 44634, 45624, 46614, 47604, 50673, 51663, 52653, 53643, 54633, 55623, 56613, 57603, 60672, 61662, 62652, 63642, 64632, 65622, 66612, 67602, 70269, 70671, 71259, 71661, 72249, 72651, 73239, 73641, 74229, 74631, 75219, 75621, 76209, 76299, 76611, 77289, 77601, 78279, 79269, 80268, 80670, 81258, 81660, 82248, 82650, 83640, 84228, 84630, 85218, 85620, 86208, 86298, 86610, 87288, 87600, 88278, 89268, 90267, 91257, 92247, 93237, 94227, 95217, 96207, 96297, 97287, 98277, 99267};

ll rev(ll x){
	ll gg = 0L;
	while(x > 0L){
		gg = gg * 10L + (x % 10L);
		x /= 10L;
	}
	return gg;
}

ll check(ll x, int attem = 0){
	if(x < MAX && conv[x] != -1) return conv[x];
	ll gg = 0, re = rev(x);
	if(attem == 60){
		if(x < MAX) conv[x] = 0;
		if(re < MAX && x%10L != 0) conv[re] = 0;
		return 0;
	}
	if(x == re) gg = x;
	else if(x <= 17858768886785871L - re) gg = check(x + re, attem + 1);
	if(x < MAX) conv[x] = gg;
	if(re < MAX && x%10L != 0) conv[re] = gg;
	return gg;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	for(int i=0; i<MAX; i++) conv[i] = -1;
	for(int i=1; i<MAX; i++) check(i);
	while(scanf("%d", &n) == 1){
		char sp[20];
		string s;
		map<string, int> M;
		for(int i=1; i<=n; i++){
			bool bigConv = binary_search(big, big + 116, i);
			if(!bigConv && conv[i] == 0) continue; // Lychrel number
			if(!bigConv){
				sprintf(sp, "%lld", conv[i]);
				s = sp;
			}
			else s = "4668731596684224866951378664";
			M[s]++;
		}
		int gg = 0;
		for(auto e : M)
			if(e.second > gg){
				s = e.first;
				gg = e.second;
			}
		printf("%s %d\n", s.c_str(), gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
