#include <cstdio>
using namespace std;

int main() {
	int t, n, A[13];
	scanf("%d", &t);
	for(int k=1; k<=t; k++){
		scanf("%d", &n);
		for(int i=1; i<=n; i++) scanf("%d", &A[i]);
		printf("Case %d: %d\n", k, A[(n+1)/2]);
	}
	return 0;
}