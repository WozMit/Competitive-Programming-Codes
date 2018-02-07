#include <bits/stdc++.h>
using namespace std;
int A[100005], ST[4*100005];

int oper(int x, int y){
	return A[x] > A[y] ? x:y;
}

void Build(int node, int i, int j){
	if(i == j) ST[node] = i;
	else{
		int m = (i+j)/2;
		Build(node<<1, i, m);
		Build((node<<1)+1, m+1, j);
		ST[node] = oper(ST[node<<1], ST[(node<<1)+1]);
	}
}

void Update(int node, int i, int j, int pos, int value){
	if(i == j && i == pos) A[pos] = value;
	else if(!(pos<i || pos >j)){
		int m = (i+j)/2;
		Update(node<<1, i, m, pos, value);
		Update((node<<1)+1, m+1, j, pos, value);
		ST[node] = oper(ST[node<<1], ST[(node<<1)+1]);
	}
}

int Query(int node, int i, int j, int iq, int jq, int proh){
	if(jq<i || iq>j) return 0;
	if(i == j && ST[node] == proh) return 0;
	if(i>=iq && j<=jq && ST[node] != proh) return ST[node];
	int m = (i+j)/2;
	int r = Query(node<<1, i, m, iq, jq, proh);
	int l = Query((node<<1)+1, m+1, j, iq, jq, proh);
	return oper(r, l);
}

int main() {
	int n, q, x, y, first, second;
	char let;
	A[0] = -10;
	while(cin >> n){
		for(int i=1; i<=n; i++) scanf("%d", &A[i]);
		Build(1, 1, n);
		scanf("%d", &q);
		while(q--){
			cin >> let >> x >> y;
			if(let == 'U') Update(1, 1, n, x, y);
			else{
				first = Query(1, 1, n, x, y, -1);
				second = Query(1, 1, n, x, y, first);
				cout << A[first]+A[second] << endl;
			}
		}
	}
	return 0;
}