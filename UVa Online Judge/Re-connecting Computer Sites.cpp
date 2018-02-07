#include <cstdio>
#include <set>
using namespace std;
set<pair<int, pair<int, int> > > E;
int p[1000007], gg2;

void Build(int n){
	for(int i=1; i<=n; i++) p[i] = i;
}

int Find(int x){
	return p[x] == x ? x: p[x] = Find(p[x]);
}

void Union(int x, int y){
	p[Find(x)] = Find(y);
}

void Krushkal(int n){
	Build(n);
	pair<int, pair<int, int> > p;
	for(set<pair<int, pair<int, int> > >::iterator i=E.begin(); i!=E.end(); ++i){
		p = *i;
		int w = p.first, a = p.second.first, b = p.second.second;
		if(Find(a) != Find(b)){
			gg2 += w;
			Union(a, b);
		}
	}
}

int main() {
	int n;
	bool flag = false;
	while(scanf("%d", &n) == 1){
		if(flag) printf("\n");
		flag = true;
		int a, b, w, gg1 = 0;
		for(int i=1; i<n; i++){
			scanf("%d %d %d", &a, &b, &w);
			gg1 += w;
		}
		printf("%d\n", gg1);
		int k, m = 2;
		while(m--){
			scanf("%d", &k);
			while(k--){
				scanf("%d %d %d", &a, &b, &w);
				E.insert(make_pair(w, make_pair(a, b)));
			}
		}
		gg2 = 0;
		Krushkal(n);
		printf("%d\n", gg2);
		E.clear();
	}
	return 0;
}