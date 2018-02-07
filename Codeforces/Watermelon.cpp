#include <cstdio>
using namespace std;

int main() {
	int w;
	while(scanf("%d", &w) == 1)
		if(w&1 || w == 2) printf("NO\n");
		else printf("YES\n");
	return 0;
}