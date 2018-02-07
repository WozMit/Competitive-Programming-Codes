#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	char s[1000005];
	int id[] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1}, jd[] = {0, -1, -1, -1, 0, 0, 0, 1, 1, 1}, t;
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		long long gg = 0, i = 0, j = 0, ux = 0, uy = 0;
		for(int k=0; s[k] != '5'; k++){
			i += id[s[k]-'0'], j += jd[s[k]-'0'];
			gg += abs(ux*j-uy*i);
			ux = i, uy = j;
		}
		if(gg&1) printf("%I64d.5\n", gg/2);
		else printf("%I64d\n", gg/2);
	}
	return 0;
}
