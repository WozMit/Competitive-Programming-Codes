#include <iostream>
const long long int MAX = 262145;
using namespace std;
typedef long long int ll;
ll ST[MAX], Lazy[MAX];

void Build(ll node, ll i, ll j){
	ST[node] = Lazy[node] = 0;
	if(i != j){
		ll m = (i+j)>>1;
		Build(node<<1, i, m);
		Build((node<<1)+1, m+1, j);
	}
}

void Refresh(ll node, ll i, ll j){
	if(Lazy[node] != 0){
		ST[node] += Lazy[node];
		if(i != j){
			ll m = (i+j)>>1;
			m = Lazy[node]/(j-i+1)*(m-i+1);
			Lazy[node<<1] += m;
			Lazy[(node<<1)+1] += Lazy[node]-m;
		}
		Lazy[node] = 0;
	}
}

void Update(ll node, ll i, ll j, ll iv, ll jv, ll val){
	Refresh(node, i, j);
	if(iv<=i && j<=jv){
		Lazy[node] += val*(j-i+1);
		Refresh(node, i, j);
	}
	else if(!(j<iv || i>jv)){
		ll m = (i+j)>>1;
		Update(node<<1, i, m, iv, jv, val);
		Update(1+(node<<1), m+1, j, iv, jv, val);
		ST[node] = ST[node<<1] + ST[1+(node<<1)];
	}
}

ll Query(ll node, ll i, ll j, ll iq, ll jq){
	if(j<iq || i>jq) return 0;
	Refresh(node, i, j);
	if(iq<=i && j<=jq) return ST[node];
	ll m = (i+j)>>1;
	ll l = Query(node<<1, i, m, iq, jq);
	ll r = Query(1+(node<<1), m+1, j, iq, jq);
	return l+r;
}

int main() {
	ll t, n, c, ch, a, b, v;
	cin >> t;
	while(t--){
		cin >> n >> c;
		Build(1, 0, n-1);
		while(c--){
			cin >> ch >> a >> b;
			switch(ch){
				case 0:
					cin >> v;
					Update(1, 0, n-1, a-1, b-1, v);
					break;
				case 1:
					cout << Query(1, 0, n-1, a-1, b-1) << endl;
					break;
			}
		}
	}
	return 0;
}