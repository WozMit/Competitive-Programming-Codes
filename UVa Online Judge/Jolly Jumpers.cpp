#include <cstdio>
#include <cmath>
#include <bitset>
using namespace std;

int main() {
	int n, x, y;
	while(scanf("%d", &n) == 1){
		scanf("%d", &x);
		bitset<3000> A;
		for(int i=0; i<n-1; i++){
			scanf("%d", &y);
			A[abs(x-y)] = 1;
			x = y;
		}
		bool flag = true;
		for(int i=1; i<n; i++)
			if(!A[i]) flag = false;
		if(flag) printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}