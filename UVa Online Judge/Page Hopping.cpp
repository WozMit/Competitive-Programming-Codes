#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int oo = 300;
int G[101][101];

int main() {
	int a, b, casE = 0, n;
	while(scanf("%d %d", &a, &b) == 2 && a && b){
		n = max(a, b);
		for(int i=1; i<=100; i++)
			for(int j=1; j<=100; j++) G[i][j] = (i == j ? 0:oo);
		G[a][b] = 1;
		while(scanf("%d %d", &a, &b) == 2 && a && b){
			G[a][b] = 1;
			n = max(n, max(a, b));
		}
		for(int k=1; k<=n; k++)
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
		double sum = 0, pairs = 0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(G[i][j] && G[i][j] < oo){
					sum += G[i][j];
					pairs++;
				}
		printf("Case %d: average length between pages = %.3f clicks\n", ++casE, sum/pairs);
	}
	return 0;
}