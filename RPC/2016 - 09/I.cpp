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
const int MAX = 255;
double G[MAX][MAX];

struct circle{
	double x, y, r;
	circle(double px, double py, double pr){ x = px, y = py, r = pr; }
	double dist(circle b){ return max(0.0, sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y))-r-b.r); }
};

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t, s, p;
	scanf("%d", &t);
	for(int te=0; te<t; te++){
		vector<circle> V;
		scanf("%d", &s);
		double x, y, r;
		for(int i=0; i<s; i++) scanf("%lf %lf %lf", &x, &y, &r), V.push_back(circle(x, y, r));
		scanf("%d", &p);
		for(int i=0; i<2*p; i++) scanf("%lf %lf", &x, &y), V.push_back(circle(x, y, 0.0));
		int n = V.size();
		for(int i=0; i<n; i++) for(int j=0; j<n; j++) G[i][j] = V[i].dist(V[j]);
		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++) G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
		printf("Campus #%d:\n", te+1);
		for(int i=0; i<p; i++) printf("Path #%d: Shortest sun distance is %.1f.\n", i+1, G[s+2*i][s+2*i+1]);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
