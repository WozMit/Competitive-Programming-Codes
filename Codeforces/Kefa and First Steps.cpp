#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, fi, se;
	while(scanf("%d", &n) == 1){
		int gg = 1, cont = 1;
		scanf("%d", &fi);
		for(int i=1; i<n; i++){
			scanf("%d", &se);
			if(se < fi) cont = 1;
			else cont++;
			gg = max(gg, cont);
			fi = se;
		}
		printf("%d\n", gg);
	}
	return 0;
}