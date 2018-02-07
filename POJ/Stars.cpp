#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 100005;
int n, bit[MAX], GG[MAX];

void Update(int idx, int val){
	while(idx <= n){
		bit[idx] += val;
		idx += idx&-idx;
	}
}

int Query(int idx){
	int sum = 0;
	while(idx){
		sum += bit[idx];
		idx -= idx&-idx;
	}
	return sum;
}

int main() {
	int x, y;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<=n; i++) bit[i] = GG[i] = 0;
		for(int i=0; i<n; i++){
			scanf("%d %d", &x, &y);
			x++;
			GG[Query(x)]++;
			Update(x, 1);
		}
		for(int i=0; i<n; i++) printf("%d\n", GG[i]);
	}
	return 0;
}