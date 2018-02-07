#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int p[1002];

int Find(int x){
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

int main() {
	int t;
	bool flag = false;
	string s;
	scanf("%d", &t);
	while(t--){
		if(flag) printf("\n\n");
		int n, g = 0, b = 0, x, y;
		scanf("%d", &n);
		for(int i=0; i<=n; i++) p[i] = i;
		char op;
		cin.ignore();
		while(getline(cin, s) && !s.empty()){
			sscanf(s.c_str(), "%c %d %d", &op, &x, &y);
			if(op == 'c') p[Find(y)] = Find(x);
			else Find(x) == Find(y) ? g++:b++;
		}
		printf("%d,%d", g, b);
		flag = true;
	}
	return 0;
}