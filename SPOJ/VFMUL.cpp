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
const int MAX = (int)6e5+13;
const double tau = acos(0)*4;
int sum[MAX];
vcd A, B;

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

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te; scanf("%d", &te);
	while(te--){
		string s, t;
		cin >> s >> t;
		bool sgn = false;
		if(s[0] == '-') sgn = true, s = s.substr(1);
		if(t[0] == '-') sgn = !sgn, t = t.substr(1);
		int n = s.size(), m = t.size(), size = 1<<(int)ceil(log2(n+m-1));
		A.resize(size);
		B.resize(size);
		for(int i=0; i<n; i++) A[n-i-1] = s[i]-'0';
		for(int i=0; i<m; i++) B[m-i-1] = t[i]-'0';
		for(int i=n; i<size; i++) A[i] = 0;
		for(int i=m; i<size; i++) B[i] = 0;
		A = fft(A);
		B = fft(B);
		for(int i=0; i<size; i++) A[i] *= B[i];
		A = fft(A, 1);
		n += m-1;
		for(int i=0; i<=n+10; i++) sum[i] = 0;
		for(int i=0; i<n; i++){
			int x = round(A[i].real()), k = i, take = 0;
			while(x || take){
				sum[k] += x%10+take;
				take = sum[k]/10;
				sum[k++] %= 10;
				x /= 10;
			}
		}
		while(sum[n]) n++;
		while(n > 1 && !sum[n-1]) n--;
		string gg = sgn ? "-":"";
		for(int i=n-1; i>=0; i--) gg += sum[i]+'0';
		printf("%s\n", gg.c_str());
	}
	#ifdef WozMit
		printf("%30c Executed in %d s.", 32, (int)((double)(clock() - _start)/CLOCKS_PER_SEC*1000));
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
