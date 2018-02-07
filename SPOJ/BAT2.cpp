//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <set>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const int MAX = 105;
int n, A[MAX], lis[MAX];
vector<int> I[MAX], S;
vector<vector<int> > V1, V2;

void Show(int idx, bool right){
	if(I[idx].size() == 0){
		if(right) V1.push_back(S);
		else V2.push_back(S);
	}
	else
		for(int i=0; i<I[idx].size(); i++){
			S.push_back(right ? I[idx][i]:(n - I[idx][i] - 1));
			Show(I[idx][i], right);
			S.pop_back();
		}
}

void Extract(bool right){
	int len = 1;
	for(int i=0; i<n; i++) I[i].clear(), lis[i] = 1;
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++)
			if(A[j] < A[i]){
				if(lis[j] + 1 > lis[i]){
					lis[i] = lis[j] + 1;
					I[i].clear();
					I[i].push_back(j);
				}
				else if(lis[j] + 1 == lis[i]) I[i].push_back(j);
			}
		len = max(len, lis[i]);
	}
	if(right) V1.clear();
	else V2.clear();
	S.clear();
	for(int i=0; i<n; i++)
		if(lis[i] == len){
			S.push_back(right ? i: (n - i - 1));
			Show(i, right);
			S.pop_back();
		}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		Extract(1);
		reverse(A, A+n);
		Extract(0);
		int gg = 0;
		for(int i=0; i<V1.size(); i++)
			for(int j=0; j<V2.size(); j++){
				set<int> Cover;
				for(int k=0; k<V1[i].size(); k++) Cover.insert(V1[i][k]);
				for(int k=0; k<V2[j].size(); k++) Cover.insert(V2[j][k]);
				gg = max(gg, (int)Cover.size());
			}
		printf("%d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
