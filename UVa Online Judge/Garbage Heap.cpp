//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = 23;
const ll oo = (ll)1e17;
ll M[MAX][MAX][MAX], P[MAX][MAX][MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	bool flag = false;
	while(te--){
		if(flag) printf("\n");
		else flag = true;
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		for(int i=0; i<a; i++)
			for(int j=0; j<b; j++)
				for(int k=0; k<c; k++){
					ll x; scanf("%lld", &x);
					M[i][j][k] = x + (j ? M[i][j-1][k]:0);
					P[i][j][k] = M[i][j][k] + (k ? P[i][j][k-1]:0);
				}
		ll gg = P[0][0][0];
		for(int l=0; l<b; l++)
			for(int j=l; j<b; j++)
				for(int h=0; h<c; h++)
					for(int k=h; k<c; k++){
						ll gg1 = -oo, max_here = gg1;
						for(int i=0; i<a; i++){
							ll x = P[i][j][k] - (l ? P[i][l-1][k]:0) - (h ? (P[i][j][h-1] - (l ? P[i][l-1][h-1]:0)):0);
							max_here = max(x, x+max_here);
							gg1 = max(gg1, max_here);
						}
						gg = max(gg, gg1);
					}
		printf("%lld\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
