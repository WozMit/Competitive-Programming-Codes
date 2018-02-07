//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <set>
#include <map>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = (int)1e3+5, m = (int)1e9+7;
int gg[MAX], nC[505][505];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	nC[0][0] = 1;
	for(int i=1; i<505; i++) nC[i][0] = 1, nC[0][i] = 0;
	for(int i=1; i<505; i++)
		for(int j=1; j<505; j++) nC[i][j] = (nC[i-1][j-1] + nC[i-1][j])%m;
	int n;
	while(scanf("%d", &n) == 1){
		int mp = n*(n-1)/2;
		vector<pair<int, int> > V(n), mid(mp);
		for(int i=0; i<n; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			V[i] = make_pair(x+x, y+y);
			gg[i+1] = 0;
		}
		gg[1] = n;
		sort(V.begin(), V.end());
		int k = 0;
		for(int i=0; i<n-1; i++)
			for(int j=i+1; j<n; j++)
				mid[k++] = make_pair((V[i].first + V[j].first)/2, (V[i].second + V[j].second)/2);
		sort(mid.begin(), mid.end());
		for(int i=0; i<mp; i++){
			bool flag = binary_search(V.begin(), V.end(), mid[i]);
			int P = 1;
			while(i+1 < mp && mid[i] == mid[i+1]) i++, P++;
			for(int p=1; p<=P; p++){
				gg[p+p] = (gg[p+p] + nC[P][p])%m;
				if(flag) gg[p+p+1] = (gg[p+p+1] + nC[P][p])%m;
			}
		}
		for(int i=1; i<n; i++) printf("%d ", gg[i]);
		printf("%d\n", gg[n]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
