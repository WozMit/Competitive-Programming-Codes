#include <bits/stdc++.h>
using namespace std;
int n, A[2002], x;

int main() {
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		for(int i=0; i<n; i++){
			int cont = 0;
			for(int j=0; j<n; j++)
				if(A[j] > A[i]) cont++;
			printf("%d ", ++cont);
		}
		printf("\n");
	}
	return 0;
}