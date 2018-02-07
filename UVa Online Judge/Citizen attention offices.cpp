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

struct area{
	int x, y, p;
	area(int px, int py, int pp){ x = px; y = py; p = pp; }
	int distance(int of){
		int i = of/5, j = of-i*5;
		return (abs(x-i)+abs(y-j))*p;
	}
};

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te;
	scanf("%d", &te);
	while(te--){
		vector<area> V;
		int n, x, y, p;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d %d %d", &x, &y, &p);
			V.push_back(area(x, y, p));
		}
		int tot = 1<<30, g1, g2, g3, g4, g5;
		for(int a=0; a<25; a++)
			for(int b=a+1; b<25; b++)
				for(int c=b+1; c<25; c++)
					for(int d=c+1; d<25; d++)
						for(int e=d+1; e<25; e++){
							int dist = 0;
							for(int i=0; i<n; i++){
								int mini = 1<<30;
								mini = min(mini, V[i].distance(a));
								mini = min(mini, V[i].distance(b));
								mini = min(mini, V[i].distance(c));
								mini = min(mini, V[i].distance(d));
								mini = min(mini, V[i].distance(e));
								dist += mini;
							}
							if(dist < tot){
								tot = dist; g1 = a; g2 = b; g3 = c; g4 = d; g5 = e;
							}
						}
		printf("%d %d %d %d %d\n", g1, g2, g3, g4, g5);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
