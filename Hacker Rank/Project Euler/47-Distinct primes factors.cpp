    //
    //	Dear maintainer:
    // 
    // Once you are done trying to 'optimize' this routine,
    // and have realized what a terrible mistake that was,
    // please increment the following counter as a warning
    // to the next guy:
    // 
    // total_hours_wasted_here = 0
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
typedef long long int ll;
const int MAX = (int)2e6+5;
int p[MAX], n, k;

void Sieve(){
	for(int i=3; i<MAX; i+=2) p[i] = i;
	for(int i=2; i<MAX; i+=2) p[i] = 2;
	for(int i=3; (ll)i*i<MAX; i+=2)
		if(p[i] == i) for(ll j=i*i; j<MAX; j+=2*i) p[j] = i;
}

vector<int> Factor(int n){
	vector<int> V;
	while(n > 1){
		int pf = p[n];
		while(n % pf == 0) n /= pf;
		V.push_back(pf);
	}
	return V;
}

bool Dist(vector<int> &A, vector<int> &B){
	if(A.size() != B.size()) return false;
	for(int i=0; i<A.size(); i++)
		for(int j=0; j<B.size(); j++)
			if(A[i] == B[j]) return false;
	return true;
}

bool Check(int i){
	vector<int> V[k];
	for(int j=0; j<k; j++) V[j] = Factor(i+j);
	for(int j=0; j<k-1; j++)
		if(V[j].size() != k || !Dist(V[j], V[j+1])) return false;
	return true;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	while(scanf("%d %d", &n, &k) == 2){
		for(int i=14; i<=n; i++)
			if(Check(i)) printf("%d\n", i);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
