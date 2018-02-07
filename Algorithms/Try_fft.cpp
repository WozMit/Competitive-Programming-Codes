//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <complex>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef complex<double> cd;
typedef vector<cd> vcd;
const int MAX = (int)1e4;
const double tau = acos(0)*4;

struct cmp{
	double r, i;
	cmp(double rp, double ip){ r = rp, i = ip; }
	cmp operator +(cmp b)const{ return cmp(r+b.r, i+b.i); }
	cmp operator *(cmp b)const{ return cmp(r*b.r-i*b.i, r*b.i+i*b.r); }
	void print(){ printf("%.3f + %.3fi\n", r, i); }
};

//as.size() must be a power of two
vcd fft(const vcd &as, bool inverse = 0){
	int n = as.size(), k = 0;
	while((1 << k) < n) k++;
	vector<int> rev(n);
	rev[0] = 0;
	int high1 = -1;
	for(int i=1; i<n; i++){
		if((i&(i-1)) == 0) high1++;
		rev[i] = rev[i^(1<<high1)];
		rev[i] |= (1<<(k-high1-1));
	}
	vcd roots(n), cur(n);
	for(int i=0; i<n; i++){
		double alpha = tau*i/n;
		roots[i] = cd(cos(alpha), sin(alpha));
		cur[i] = as[rev[i]];
	}
	for(int len=1; len<n; len <<= 1){
		vcd ncur(n);
		int rstep = roots.size()/(len*2);
		for(int pdest = 0; pdest<n;){
			int p1 = pdest;
			for(int i=0; i<len; i++){
				cd val = roots[i*rstep]*cur[p1+len];
				ncur[pdest] = cur[p1] + val;
				ncur[pdest+len] = cur[p1] - val;
				pdest++, p1++;
			}
			pdest += len;
		}
		cur.swap(ncur);
	}
	if(inverse){
		for(int i=0; i<(int)cur.size(); i++) cur[i] /= as.size();
		reverse(cur.begin()+1, cur.end());
	}
	return cur;
}


int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n; scanf("%d", &n);
	vcd as(n);
	for(int i=0; i<n; i++){
		int x; scanf("%d", &x);
		as[i] = x;
	}
	while(__builtin_popcount(n) != 1) as.push_back(0), n++;
	vcd res = fft(as);
	for(int i=0; i<n; i++) printf("(%.4lf, %.4lf) ", res[i].real(), res[i].imag());
	printf("\n------------------\n");
	vcd as2 = fft(res, 1);
	for(int i=0; i<n; i++) printf("%.4lf ", as2[i].real());
	printf("\n");
	#ifdef WozMit
		printf("%30c Executed in %.2f ms.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC*1000);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
