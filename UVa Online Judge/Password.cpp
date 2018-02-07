//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#include <set>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
vector<int> G1[10], G2[10], GG;
set<string> What;

void bt(int col){
	if(col == 5){
		string gg = "";
		for(int i=0; i<5; i++) gg += char(GG[i]);
		What.insert(gg);
	}
	else{
		for(int i=0; i<6; i++)
			if(binary_search(G2[col].begin(), G2[col].end(), G1[col][i])){
				GG.push_back(G1[col][i]);
				bt(col+1);
				GG.pop_back();
			}
	}
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int te, k; scanf("%d", &te);
	while(te--){
		scanf("%d", &k);
		char c;
		for(int i=0; i<6; i++)
			for(int j=0; j<5; j++){
				scanf(" %c", &c);
				G1[j].push_back(c);
			}
		for(int i=0; i<6; i++)
			for(int j=0; j<5; j++){
				scanf(" %c", &c);
				G2[j].push_back(c);
			}
		for(int i=0; i<5; i++){
			sort(G1[i].begin(), G1[i].end());
			sort(G2[i].begin(), G2[i].end());
		}
		GG.clear();
		What.clear();
		bt(0);
		if(What.size() >= k){
			set<string>::iterator i;
			int othercounter = 0;
			for(i = What.begin(); i!=What.end(); i++, othercounter++)
				if(othercounter == k-1) break;
			printf("%s\n", (*i).c_str());
		}
		else printf("NO\n");
		for(int i=0; i<10; i++) G1[i].clear(), G2[i].clear();
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
