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

//A.size() must be a power of two
vcd fft(const vcd &A, bool inverse = 0){
	int n = A.size(), k = 0;
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
		cur[i] = A[rev[i]];
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
		for(int i=0; i<(int)cur.size(); i++) cur[i] /= A.size();
		reverse(cur.begin()+1, cur.end());
	}
	return cur;
}

vcd get(vcd &A, vcd &B){
	int kprev = A.size()+B.size()-1;
	int k = 1<<(int)ceil(log2(kprev));
	A.resize(k);
	B.resize(k);
	A = fft(A);
	B = fft(B);
	for(int i=0; i<k; i++) A[i] *= B[i];
	A = fft(A, 1);
	A.resize(kprev);
	return A;
}


int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n, m; scanf("%d", &n);
	vcd A(n);
	for(int i=0; i<n; i++){
		int x; scanf("%d", &x);
		A[i] = x;
	}
	scanf("%d", &m);
	vcd B(m);
	for(int i=0; i<m; i++){
		int x; scanf("%d", &x);
		B[i] = x;
	}
	vcd convolution = get(A, B);
	for(int i=0; i<convolution.size(); i++){
		int x = round(convolution[i].real());
		printf("%d ", x);
	}
	printf("\n");
	#ifdef WozMit
		printf("%30c Executed in %d ms.", 32, (int)((double)(clock() - _start)/CLOCKS_PER_SEC*1000));
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
