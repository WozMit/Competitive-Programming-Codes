//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
int S[50002];
pii ST[150006];

int Sum(int i, int j){return i == 0 ? S[j]:S[j]-S[i-1];}

pii oper(pii p1, pii p2){
	int a = p1.first, b = p1.second, c = p2.first, d = p2.second;
	int s1 = Sum(a, b), s2 = Sum(c, d), s3 = Sum(a, d);
	if(s1 > s3 && s1 > s2) return make_pair(a, b);
	if(s2 > s1 && s2 > s3) return make_pair(c, d);
	return make_pair(a, d);
}

void Build(int node, int i, int j){
	if(i == j) ST[node] = make_pair(i, i);
	else{
		int m = (i+j)>>1;
		Build(node<<1, i, m);
		Build((node<<1)+1, m+1, j);
		ST[node] = oper(ST[node<<1], ST[(node<<1)+1]);
	}
}

pii Query(int node, int i, int j, int iq, int jq){
	if(jq<i || j<iq) return make_pair(-123546, -123546);
	if(iq<=i && j<=jq) return ST[node];
	int m = (i+j)>>1;
	pii l = Query(node<<1, i, m, iq, jq);
	pii r = Query((node<<1)+1, m+1, j, iq, jq);
	if(l.first == -123546) return r;
	if(r.first == -123546) return l;
	return oper(l, r);
}

int main() {
	int n, x;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++){
			scanf("%d", &x);
			if(!i) S[0] = x;
			else S[i] = S[i-1] + x;
		}
		Build(1, 0, n-1);
		scanf("%d", &x);
		int a, b;
		while(x--){
			scanf("%d%d", &a, &b);
			pii gg = Query(1, 0, n-1, a-1, b-1);
			printf("%d\n", Sum(gg.first, gg.second));
		}
	}
	return 0;
}