#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int ll;
double eps = 0.0000000001;

bool Integer(double x){ return (abs(x-(int)x) < eps || abs(x-(int)(x+1.0)) < eps); }

int main(){
	int n;
	while(scanf("%d", &n) == 1){
		int gg = 0;
		for(int i=1; i<=n/2; i++)
			if(Integer((1+sqrt(4*(2*n+(ll)i*(i-1ll))+1ll))/2.0)) gg++;
		printf("%d\n", gg+1);
	}
	return 0;
}
