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
const int MAX = (int)1e3+5;
char s[MAX];
int n, mod, pow10[MAX], dp[MAX][MAX];

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	while(scanf("%s %d", &s, &mod) == 2){
		n = strlen(s);
		pow10[0] = 1%mod;
		for(int i=1; i<n; i++) pow10[i] = 10*pow10[i-1]%mod;
		for(int i=0; i<n; i++)
			for(int r=0; r<mod; r++) dp[i][r] = -1;
		int mini = min(10, mod);
		for(int r=0; r<mini; r++){
			int digit = isdigit(s[n-1]) ? s[n-1]-'0':-1;
			for(int k=(digit == -1 ? (n == 1 ? 1:0):digit); k<10; k++){
				if(k%mod == r){
					dp[n-1][r] = k;
					break;
				}
				if(digit != -1) break;
			}
		}
		for(int i=n-2; i>=0; i--){
			int digit = isdigit(s[i]) ? s[i]-'0':-1;
			for(int r=0; r<mod; r++){
				for(int k=(digit == -1) ? (i ? 0:1):digit; k<10; k++){
					if(dp[i+1][(mod + r - k*pow10[n-i-1]%mod)%mod] != -1){
						dp[i][r] = k;
						break;
					}
					if(digit != -1) break;
				}
			}
		}
		if(dp[0][0] == -1) puts("*");
		else{
			int r = 0;
			for(int i=0; i<n; i++){
				s[i] = dp[i][r] + '0';
				r = (mod + r - dp[i][r]*pow10[n-i-1]%mod)%mod;
			}
			printf("%s\n", s);
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
