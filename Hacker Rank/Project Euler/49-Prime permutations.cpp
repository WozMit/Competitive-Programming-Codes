    //
    //	Dear maintainer:
    // 
    // Once you are done trying to 'optimize' this routine,
    // and have realized what a terrible mistake that was,
    // please increment the following counter as a warning
    // to the next guy:
    // 
    // total_hours_wasted_here = 0
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
#include <map>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
typedef long long int ll;
const int MAX = (int)1e6+5;
bitset<MAX> prime;
map<vector<int>, vector<int> > B;

void Sieve(){
	prime.set();
	prime[0] = prime[1] = false;
	for(int i=2; i<MAX; i++)
		if(prime[i]){
			for(int j=i+i; j<MAX; j+=i) prime[j] = false;
			vector<int> V;
			int t = i;
			while(t) V.push_back(t%10), t /= 10;
			sort(V.begin(), V.end());
			B[V].push_back(i);
		}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	Sieve();
	int n, k;
	while(scanf("%d %d", &n, &k) == 2){
		vector<vector<int> > gg;
		for(map<vector<int>, vector<int> >::iterator it = B.begin(); it!=B.end(); it++){
			vector<int> &primes = it -> second;
			for(int i=0; i<(int)primes.size()-k+1 && primes[i] < n; i++)
				for(int j=i+1; j<(int)primes.size()-k+2; j++){
					int dif = primes[j]-primes[i], next = primes[j] + dif;
					vector<int> V;
					V.push_back(primes[i]);
					V.push_back(primes[j]);
					for(int h=j+1; h<primes.size() && primes[h] <= next && V.size() < k; h++)
						if(primes[h] == next){
							V.push_back(primes[h]);
							next += dif;
						}
					if(V.size() == k) gg.push_back(V);
				}
		}
		sort(gg.begin(), gg.end());
		for(int i=0; i<gg.size(); i++){
			for(int j=0; j<k; j++) printf("%d", gg[i][j]);
			printf("\n");
		}
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
