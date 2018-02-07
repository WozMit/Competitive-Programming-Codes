#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int ll;
int main(){
	int i,n,t,j,flag,visited[105];
	char a[105][105];
	while(scanf("%d",&n) == 1){
		for(i=0;i<n;i++){
			visited[i]=0;
			scanf("%s",a[i]);
		}
		int ans=1,c,k;
		for(i=0;i<n;i++){
			if(visited[i]) continue;
			c=1;
			for(j=i+1;j<n;j++){
				flag=1;
				if(visited[j]) continue;
				for(k=0;k<n;k++){
					if(a[i][k]!=a[j][k]){
						flag=0;
						break;
					}
				}
				if(flag) c++;
			}
		ans=max(ans,c);
		}
		printf("%d\n",ans);
	}
	return 0;
}