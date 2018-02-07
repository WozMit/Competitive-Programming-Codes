//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <bitset>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
const double eps = 1e-3;
const int MAX = 2505;
double logfact[MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	logfact[0] = logfact[1] = 0.0;
	for(int i=2; i<MAX; i++) logfact[i] = logfact[i-1] + log(i);
	int t, na, nb, nc, n;
	scanf("%d", &t);
	for(int te=0; te<t; te++){
		scanf("%d %d %d", &na, &nb, &nc);
		double a = 0.0, b = 0.0, c = 0.0;
		while(na--) scanf("%d", &n), a += logfact[n];
		while(nb--) scanf("%d", &n), b += logfact[n];
		while(nc--) scanf("%d", &n), c += logfact[n];
		double maxi = max(a, max(b, c));
		if((abs(a-maxi) < eps && abs(b-maxi) < eps) || (abs(a-maxi) < eps && abs(c-maxi) < eps)
		|| (abs(c-maxi) < eps && abs(b-maxi) < eps)) printf("Case #%d: TIE\n", te+1);
		else if(abs(a-maxi) < eps) printf("Case #%d: A\n", te+1);
		else if(abs(b-maxi) < eps) printf("Case #%d: B\n", te+1);
		else printf("Case #%d: C\n", te+1);
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
