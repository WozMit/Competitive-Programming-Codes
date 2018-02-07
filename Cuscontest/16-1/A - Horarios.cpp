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
typedef pair<int, int> pii;
#define fi first
#define se second
#define p make_pair

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t, n, a, b;
	pii A[5005];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d %d", &a, &b);
			A[i] = p(a, b);
		}
		sort(A, A+n);
		vector<pii> V;
		for(int i=0; i<n; i++)
			if(A[i].fi != -1){
				a = A[i].fi;
				b = A[i].se;
				for(int j=i+1; j<n; j++)
					if(A[j].fi != -1 && b >= A[j].fi) b = max(b, A[j].se), A[j] = p(-1, 0);
				V.push_back(p(a, b));
			}
		int gg1 = 0, gg2 = 0;
		for(int i=0; i<V.size()-1; i++) gg1 = max(gg1, V[i+1].fi-V[i].se);
		for(int i=0; i<V.size(); i++) gg2 = max(gg2, V[i].se-V[i].fi);
		printf("%d %d\n", gg1, gg2);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
