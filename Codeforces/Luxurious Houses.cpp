#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100005;

int main() {
	int n, A[MAX], M[MAX];
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		M[n-1] = -1;
		for(int i=n-2; i>-1; i--) M[i] = max(M[i+1], A[i+1]);
		for(int i=0; i<n; i++)
			if(M[i] >= A[i]) printf("%d ", M[i]-A[i]+1);
			else printf("0 ");
		printf("\n");
	}
	return 0;
}