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
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
int S[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60}; // 43 elem

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n;
	while(scanf("%d", &n) == 1 && n > 0){
		int gg1 = 0, gg2 = 0;
		for(int a=0; a<43; a++)
			for(int b=a; b<43; b++)
				for(int c=b; c<43; c++)
					if(S[a] + S[b] + S[c] == n){
						int v1 = S[a], v2 = S[b], v3 = S[c];
						gg1++;
						if((v1 == v2 && v1 != v3) || (v1 == v3 && v1 != v2) || (v2 == v3 && v2 != v1))
							gg2 += 3;
						else if(v1 != v2 && v2 != v3 && v1 != v3) gg2 += 6;
						else if(v1 == v2 && v2 == v3) gg2 ++;
					}
		if(!gg1) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		else{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, gg1);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, gg2);
		}
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
