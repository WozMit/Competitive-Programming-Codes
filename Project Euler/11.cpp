#include <bits/stdc++.h>
using namespace std;

int main() {
	int A[20][20];
	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++) scanf("%d", &A[i][j]);
	int gg = 0;
	for(int i=0; i<17; i++)
		for(int j=0; j<17; j++){
			gg = max(gg, A[i][j]*A[i][j+1]*A[i][j+2]*A[i][j+3]);
			gg = max(gg, A[i][j]*A[i+1][j]*A[i+2][j]*A[i+3][j]);
			gg = max(gg, A[i][j]*A[i+1][j+1]*A[i+2][j+2]*A[i+3][j+3]);
			if(j>2) gg = max(gg, A[i][j]*A[i+1][j-1]*A[i+2][j-2]*A[i+3][j-3]);
		}
	printf("%d\n", gg);
	return 0;
}