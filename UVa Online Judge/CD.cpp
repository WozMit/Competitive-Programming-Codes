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
vector<int> GG;
int k, n, A[30], gg;

void bt(vector<int> S, int pos, int sum){
	sum += A[pos];
	S.push_back(A[pos]);
	if(sum > gg || (sum == gg && S.size() > GG.size())){
		gg = sum;
		GG = S;
	}
	for(int i=pos+1; i<n; i++)
		if(sum+A[i] <= k) bt(S, i, sum);
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d %d", &k, &n) == 2){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		gg = 0;
		for(int i=0; i<n; i++){
			vector<int> V;
			bt(V, i, 0);
		}
		for(int i=0; i<GG.size(); i++) printf("%d ", GG[i]);
		printf(" sum:%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
