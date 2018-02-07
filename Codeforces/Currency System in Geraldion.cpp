#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n;
	while(scanf("%d", &n) == 1){
		int gg = 1000005, a;
		while(n--){
			scanf("%d", &a);
			if(a < gg) gg = a;
		}
		if(gg == 1) printf("-1\n");
		else printf("1\n");
	}
	return 0;
}