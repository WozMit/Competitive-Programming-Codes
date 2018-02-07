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
const int MAX = (int)(1<<20)+5, MAX1 = (int)6e5+13;
const double tau = 4*acos(0);
cd A[MAX], B[MAX], roots[MAX], cur[MAX], ncur[MAX];
int rev[MAX], sum[MAX1];

void fft(cd *A, int n, bool inverse = 0){
	int k = 0, high1 = -1;
	while((1 << k) < n) k++;
	rev[0] = 0;
	for(int i=1; i<n; i++){
		if((i&(i-1)) == 0) high1++;
		rev[i] = rev[i^(1<<high1)];
		rev[i] |= (1<<(k-high1-1));
	}
	for(int i=0; i<n; i++){
		double alpha = tau*i/n;
		roots[i] = cd(cos(alpha), sin(alpha));
		cur[i] = A[rev[i]];
	}
	for(int len=1; len<n; len <<= 1){
		int rstep = n/(len*2);
		for(int pdest = 0; pdest<n; pdest += len){
			int p1 = pdest;
			for(int i=0; i<len; i++, pdest++){
				cd val = roots[i*rstep]*cur[p1+len];
				ncur[pdest] = cur[p1] + val;
				ncur[pdest+len] = cur[p1++] - val;
			}
		}
		for(int i=0; i<n; i++) swap(cur[i], ncur[i]);
	}
	if(inverse){
		for(int i=0; i<n; i++) cur[i] /= n;
		reverse(cur+1, cur+n);
	}
	for(int i=0; i<n; i++) A[i] = cur[i];
}

/*string multiply(string &s, string &t){
	bool sgn = false;
	if(s[0] == '-') sgn = true, s = s.substr(1);
	if(t[0] == '-') sgn = !sgn, t = t.substr(1);
	int n = s.size(), m = t.size(), size = 1<<(int)ceil(log2(n+m-1));
	for(int i=0; i<n; i++) A[n-i-1] = s[i]-'0';
	for(int i=0; i<m; i++) B[m-i-1] = t[i]-'0';
	for(int i=n; i<size; i++) A[i] = 0;
	for(int i=m; i<size; i++) B[i] = 0;
	fft(A, size);
	fft(B, size);
	for(int i=0; i<size; i++) A[i] *= B[i];
	fft(A, size, 1);
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
	return gg;
}*/

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
		for(int i=0; i<n; i++) A[n-i-1] = s[i]-'0';
		for(int i=0; i<m; i++) B[m-i-1] = t[i]-'0';
		for(int i=n; i<size; i++) A[i] = 0;
		for(int i=m; i<size; i++) B[i] = 0;
		fft(A, size);
		fft(B, size);
		for(int i=0; i<size; i++) A[i] *= B[i];
		fft(A, size, 1);
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
