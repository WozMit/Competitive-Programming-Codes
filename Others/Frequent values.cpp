#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int A[MAX];
pair<int, int> ST[3*MAX];

pair<int, int> oper(pair<int, int> a, pair<int, int> b){
	pair<int, int> p;
	if(a.first = b.first) p = make_pair(a.first, a.second+b.second);
	else p = a.second > b.second ? a:b;
	return p;
}

void Build(int node, int i, int j){
	if(i == j) ST[node] = make_pair(A[i], 1);
	else{
		int m = (i+j)/2;
		Build(2*node, i, m);
		Build(2*node+1, m+1, j);
		ST[node] = oper(ST[2*node], ST[2*node+1]);
	}
}

pair<int, int> Query(int node, int i, int j, int iq, int jq){
	if(jq<i || j<iq) return make_pair(0, -1);
	if(iq<=i && j<=jq) return ST[node];
	int m = (i+j)/2;
	pair<int, int> l = Query(2*node, i, m, iq, jq);
	pair<int, int> r = Query(2*node+1, m+1, j, iq, jq);
	if(l.second == -1) return r;
	if(r.second == -1) return l;
	return oper(l, r);
}

int main() {
	int n, q, qi, qj;
	while(cin >> n >> q){
		for(int i=0; i<n; i++) cin >> A[i];
		Build(1, 0, n-1);
		for(int i=0; i<q; i++){
			cin >> qi >> qj;
			cout << Query(1, 0, n-1, qi-1, qj-1).second << endl;
		}
		cin >> n;
	}
	return 0;
}