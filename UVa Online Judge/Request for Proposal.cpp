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

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, p, te = 0;
	while(scanf("%d %d", &n, &p) == 2 && !(!n && !p)){
		if(te) printf("\n");
		string s;
		cin.ignore();
		for(int i=0; i<n; i++) getline(cin, s);
		double comp = 0.0, ggprice = 2000.0;
		string gg, a;
		while(p--){
			getline(cin, s);
			double price; int req;
			scanf("%lf %d", &price, &req);
			cin.ignore();
			for(int i=0; i<req; i++) getline(cin, a);
			double act = (double)req/(double)n;
			if(act > comp){
				comp = act;
				gg = s;
				ggprice = price;
			}
			else if(act == comp && price < ggprice){
				gg = s;
				ggprice = price;
			}
		}
		printf("RFP #%d\n%s\n", ++te, gg.c_str());
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
