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
const int MAX = (int)1e6+5;
int A[] = {2, 1, 51, 2, -1, 6, 2, 12, 56, -92}, n;
int bitc[MAX], biti[MAX];

//point-update range-query (single bit needed)

void Update(int x, int val, int *bit){	//Adds value val to position x
	for(; x<=n; x += x&(-x))
		bit[x] += val;
}

int Query(int x, int *bit){	//Returns the sum of [1:x]
	int gg = 0;
	for(; x>0; x -= x&(-x))
		gg += bit[x];
	return gg;
}

//range-update point-query (single bit needed)

void Update_r(int x, int y, int val, int *bit){	//Adds value val to all elements in [x:y]
	Update(x, val, bit);
	Update(y+1, -val, bit);
}

int Query_point(int x, int *bit){	//Returns the value of [x]
	int gg = 0;
	for(; x>0; x -= x&(-x))
		gg += bit[x];
	return gg;
}

//range-update range-query (double bit needed)

void Update_range(int x, int y, int val){	//Adds value val to all elements in [x:y]
	Update_r(x, y, val, bitc);
	Update_r(x, y, -val*(x - 1), biti);
	Update_r(y+1, n, val*(y - x + 1), biti);
}

int Query_range(int x){	//Returns the sum of [1:x]
	int a = Query_point(x, bitc);
	int b = Query_point(x, biti);
	return a*x + b;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	n = 10;
	for(int i=0; i<n; i++) Update_range(i+1, i+1, A[i]);
	for(int i=0; i<n; i++) cout << A[i] << " ";
	cout << endl;
	Update_range(2, 4, 5);
	db(Query_range(4));
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
