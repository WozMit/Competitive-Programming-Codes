//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = (int)1e5+7;
int A[MAX], B[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, k;
	while(scanf("%d", &n) == 1){
		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		for(int i=0; i<n; i++) A[i]--;
		k = 0;
		for(int i=0; i<n; i++)
			if(A[i] != -1){
				int count = 0, pos = i;
				while(A[pos] != -1){
					int temp = pos;
					pos = A[pos];
					A[temp] = -1;
					count++;
				}
				B[k++] = count;
			}
		ll gg = 0L;
		if(k == 1) gg = (ll)B[0]*B[0];
		else{
			sort(B, B+k);
			gg += (ll)(B[k-1] + B[k-2]) * (B[k-1] + B[k-2]);
			for(int i=0; i<k-2; i++) gg += (ll)B[i]*B[i];
		}
		printf("%I64d\n", gg);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
