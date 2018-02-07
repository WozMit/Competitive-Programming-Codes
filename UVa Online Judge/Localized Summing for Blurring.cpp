#include <cstdio>
int M[1000][1000];

int main() {
	int n, m;
	bool flag = false;
	while(scanf("%d%d", &n, &m) == 2){
		if(flag) printf("\n");
		flag = true;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				scanf("%d", &M[i][j]);
				M[i][j] += M[i-1][j] + M[i][j-1] - M[i-1][j-1];
			}
		int p = n-m+1, gg = 0;
		m--;
		for(int i=0; i<p; i++)
			for(int j=0; j<p; j++){
				int aux = M[i+m][j+m]-M[i+m][j-1]-M[i-1][j+m]+M[i-1][j-1];
				gg += aux;
				printf("%d\n", aux);
			}
		printf("%d\n", gg);
	}
	return 0;
}