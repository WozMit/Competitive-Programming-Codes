//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <time.h>
#include <stack>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
const int MAX = 5000007;
int val[MAX], gg[MAX];

int main(){
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	stack<ll> S;
	for(int i=2; i<MAX; i++){
		ll temp = i;
		while(temp > 1ll && (temp >= MAX || !val[temp])){
			S.push(temp);
			if(temp%2ll == 0ll) temp = temp/2ll;
			else temp = 3ll*temp+1ll;
		}
		int steps = val[temp]+1;
		for(; !S.empty(); steps++){
			ll v = S.top();
			S.pop();
			if(v < MAX) val[v] = steps;
		}
	}
	for(int i=1; i<MAX; i++) gg[i] = val[i] >= val[gg[i-1]] ? i:gg[i-1];
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", gg[n]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
