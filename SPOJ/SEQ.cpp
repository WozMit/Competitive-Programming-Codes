#include <cstdio>
#include <cstring>
using namespace std;
typedef long long int ll;
const ll m = (ll)1e9;
int k;
struct Mtx{
	int M[10][10];
	Mtx(){
		memset(M, 0, sizeof M);
		for(int i=0; i<k-1; i++) M[i][i+1] = 1;
	}
	Mtx I(){
		Mtx GG;
		memset(GG.M, 0, sizeof GG.M);
		for(int i=0; i<k; i++) GG.M[i][i] = 1;
		return GG;
	}
	Mtx operator *(Mtx B)const{
		Mtx GG;
		for(int i=0; i<k; i++)
			for(int j=0; j<k; j++){
				ll sum = 0;
				for(int h=0; h<k; h++) sum = (sum+((ll)M[i][h]*(ll)B.M[h][j])%m)%m;
				GG.M[i][j] = (int)sum;
			}
		return GG;
	}
};

Mtx Exp(Mtx A, int b){
	Mtx GG = Mtx();
	if(!b) return GG.I();
	GG = Exp(A, b/2);
	GG = GG*GG;
	if(b&1) return GG*A;
	return GG;
}

int main() {
	int te, C[10], n;
	scanf("%d", &te);
	while(te--){
		scanf("%d", &k);
		Mtx T = Mtx();
		for(int i=0; i<k; i++) scanf("%d", &C[i]);
		for(int i=k-1; i>=0; i--) scanf("%d", &T.M[k-1][i]);
		scanf("%d", &n);
		T = Exp(T, n-1);
		int gg = 0;
		for(int i=0; i<k; i++) gg = (gg+((ll)T.M[0][i]*(ll)C[i])%m)%m;
		printf("%d\n", gg);
	}
	return 0;
}