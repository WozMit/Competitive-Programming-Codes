#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set<pair<int, pair<int, int> > > E;
int p[30];

void Build(int n){
	for(int i=0; i<n; i++) p[i] = i;
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
	for(set<pair<int, pair<int, int> > >::iterator i=E.begin(); i!=E.end(); i++){
		p = *i;
		int w = p.first, a = p.second.first, b = p.second.second;
		if(Find(a) != Find(b)){
			Union(a, b);
			printf("%c-%c %d\n", a+65, b+65, w);
		}
	}
}

int main() {
	int t, n;
	scanf("%d", &t);
	for(int k=1; k<=t; k++){
		scanf("%d", &n);
		int x;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				scanf("%d,", &x);
				if(x && j>i) E.insert(make_pair(x, make_pair(i, j)));
			}
		printf("Case %d:\n", k);
		Krushkal(n);
		E.clear();
	}
	return 0;
}