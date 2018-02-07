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
int d[] = {0x7e, 0x30, 0x6d, 0x79, 0x33, 0x5b, 0x5f, 0x70, 0x7f, 0x7b}, A[15], n;
bool gg;

void bt(int pos, int dig, int bads){
	if(pos == n) gg = true;
	else{
		int actual = A[pos], digit = d[dig];
		if(!(actual&bads) && !((digit^actual)&actual)) bt(pos+1, dig-1, bads|(actual^digit));
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%d", &n) == 1 && n){
		for(int i=0; i<n; i++){
			int numb = 0;
			char c;
			for(int j=0; j<7; j++){
				scanf(" %c", &c);
				if(c == 'Y') numb |= 1<<(6-j);
			}
			A[i] = numb;
		}
		gg = false;
		for(int i=9; !gg && i>n-2; i--) bt(0, i, 0);
		if(gg) printf("MATCH\n");
		else printf("MISMATCH\n");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
