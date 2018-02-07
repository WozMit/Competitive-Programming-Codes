#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int oo = 1<<30;
int obj[23][23], c, memo[23][202];

int doit(int pos, int rem){
	if(pos == c){
		if(rem < 0) return -oo;
		return 0;
	}
	if(rem <= 0) return -oo;
	if(memo[pos][rem] != -1) return memo[pos][rem];
	int ans = -oo;
	for(int i=1; i<=obj[pos][0]; i++)
		ans = max(ans, obj[pos][i] + doit(pos+1, rem-obj[pos][i]));
	return memo[pos][rem] = ans;
}

int main() {
	int t, m;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &m, &c);
		for(int i=0; i<c; i++){
			scanf("%d", &obj[i][0]);
			for(int j=1; j<=obj[i][0]; j++) scanf("%d", &obj[i][j]);
		}
		memset(memo, -1, sizeof memo);
		int gg = doit(0, m);
		if(gg < 0) printf("no solution\n");
		else printf("%d\n", gg);
	}
	return 0;
}