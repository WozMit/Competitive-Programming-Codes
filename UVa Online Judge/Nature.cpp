#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int p[5005], size[5005];
map<string, int> M;

int Find(int x){
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int a, int b){
	int x = Find(a), y = Find(b);
	if(x != y){
		p[y] = x;
		size[x] += size[y];
	}
}

int main() {
	int n, r;
	char s1[31], s2[31];
	string a, b;
	while(scanf("%d%d", &n, &r) == 2, n || r){
		for(int i=0; i<n; i++){
			scanf("%s", s1);
			a = string(s1);
			M[a] = p[i] = i;
			size[i] = 1;
		}
		int gg = 1;
		while(r--){
			scanf("%s%s", s1, s2);
			a = string(s1); b = string(s2);
			Union(M[a], M[b]);
			gg = max(gg, size[Find(M[a])]);
		}
		printf("%d\n", gg);
	}
	return 0;
}