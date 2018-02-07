#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int a, b;
	while(scanf("%d %d", &a, &b) == 2)
		printf("%d %d\n", min(a, b), abs(a-b)>>1);
	return 0;
}