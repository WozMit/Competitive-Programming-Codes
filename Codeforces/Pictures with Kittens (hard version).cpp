//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <cassert>
#include <stack>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = (int)5e3 + 5;
const ll oo = (ll)1e15;
int A[MAX];
ll dp[MAX][2];

struct myQueue {
	stack<pair<ll, ll> > s1, s2;
	
	int size() {
		return s1.size() + s2.size();
	}
	
	bool isEmpty() {
		return size() == 0;
	}
	
	long long getMax() {
		if (isEmpty()) return -oo;
		if (!s1.empty() && !s2.empty()) {
			return max(s1.top().second, s2.top().second);
		}
		if (!s1.empty()) {
			return s1.top().second;
		}
		return s2.top().second;
	}
	
	void push(long long val) {
		if (s2.empty()) {
			s2.push(make_pair(val, val));
		} else {
			s2.push(make_pair(val, max(val, s2.top().second)));
		}
	}
	
	void pop() {
		if (s1.empty()) {
			while (!s2.empty()) {
				if (s1.empty()) {
					s1.push(make_pair(s2.top().first, s2.top().first));
				} else {
					s1.push(make_pair(s2.top().first, max(s2.top().first, s1.top().second)));	
				}
				s2.pop();
			}
		}
		assert(!s1.empty());
		s1.pop();
	}
};

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, k, x;
	while(scanf("%d %d %d", &n, &k, &x) == 3){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		dp[0][0] = 0;
		for(int i=1; i<=n; i++) dp[i][0] = -oo;
		vector<myQueue> V(x);
		int j0 = 0, j1 = 1;
		for(int j=1; j<=x; j++){
			for(int i=1; i<=n; i++){
				V[j - 1].push(dp[i - 1][j0]);
				dp[i][j1] = A[i - 1] + V[j - 1].getMax();
				if(i >= k) V[j - 1].pop();
			}
			swap(j0, j1);
		}
		ll gg = -oo;
		for(int i=n-k+1; i<=n; i++) gg = max(gg, dp[i][j0]);
		if(gg < 0) puts("-1");
		else printf("%I64d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
