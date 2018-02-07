//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <bitset>
#include <set>
#define db(x) cout << #x << " = " << x << "\n"
using namespace std;
typedef long long int ll;
const int MAX = (int)1e5+3;
int Unique[17];
bool Base[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	scanf("%d", &n);
	set<int> S;
	for(int p = 1; p<17; p++){
		for(int b = 2; b<=n; b++) S.insert(p*b);
		Unique[p] = S.size();
	}
	ll gg = 0;
	for(int i=1; i<MAX; i++) Base[i] = true;
	for(int i=2; i<=n; i++)
		if(Base[i]){
			int pw = 0;
			for(ll j=i; j<=n; j*=i, pw++) Base[j] = false;
			gg += Unique[pw];
		}
	printf("%lld\n", gg);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s";
	#endif
	return 0;
}
