#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
long long int A[128], gg;
char s[1002];

int main() {
	int n;
	scanf("%d", &n);
	while(n--){
		memset(A, 0, sizeof A);
		int k;
		scanf("%d", &k);
		char c;
		while (k--){
			getchar();
			char c = getchar();
			if (c < 0  ||  c > 127)
				while (1);
			scanf("%lld", &A[c]);
		}
		scanf("%d", &k);
		getchar();
		gg = 0;
		while(k--){
			gets(s);
			for(int i=0; s[i]; i++) gg += A[s[i]];
		}
		printf("%.2lf$\n", 0.01 * gg);
	}
	return 0;
}