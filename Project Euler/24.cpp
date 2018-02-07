#include <bits/stdc++.h>
using namespace std;
int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
	int k = 0;
	do{
		if(++k == (int)1e6){
			for(int i=0; i<10; i++) printf("%d", A[i]);
			printf("\n");
		}
	}while(next_permutation(A, A+10));
	return 0;
}
