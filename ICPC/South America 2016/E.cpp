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
int A[] = {3, 3, 9, 1, 2, 1, 7, 6, 4, 8, 9, 4, 3, 7, 5, 9, 2, 7, 3, 5, 1, 3}, mid;

bool Condition(int x){ return x <= mid; }

struct wt{
	int lo, hi;
	vector<int> mapl;
	wt *l, *r;
	wt(int *from, int *to, int plo, int phi){
		if(plo < phi && from < to){
			lo = plo;
			hi = phi;
			mid = lo + (hi - lo)/2;
			mapl.reserve(to - from + 1);
			mapl.push_back(0);
			for(int *it = from; it != to; it++)
				mapl.push_back(mapl.back() + (*it <= mid));
			db(mid);
			for(int i=0; i<mapl.size(); i++) cout << mapl[i] << " ";
			cout << endl;
			int *pivot = stable_partition(from, to, Condition);
			l = new wt(from, pivot, lo, mid);
			r = new wt(pivot, to, mid+1, hi);
		}
	}
};

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	wt T(A, A+22, 1, 9);
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
