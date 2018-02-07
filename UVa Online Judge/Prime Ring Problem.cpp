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
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}, n, A[20];
bool V[20];

bool prime(int x){
	for(int i=0; i<11; i++) if(p[i] == x) return true;
	return false;
}

void bt(int pos){
	if(pos == n && prime(A[0]+A[n-1])){
		for(int i=0; i<n-1; i++) printf("%d ", A[i]);
		printf("%d\n", A[n-1]);
	}
	else{
		for(int i=2; i<=n; i++)
			if(!V[i] && prime(A[pos-1]+i)){
				V[i] = true;
				A[pos] = i;
				bt(pos+1);
				V[i] = false;
			}
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te = 0; A[0] = 1;
	memset(V, 0, sizeof V);
	while(scanf("%d", &n) == 1){
		if(te) printf("\n");
		printf("Case %d:\n", ++te);
		bt(1);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
