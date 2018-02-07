#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int M[9][9], n, k;
bool Vr[9][10], Vc[9][10], Va[9][10], flag;
vector<pair<int, int> > V;

int Area(int i, int j){
	if(n == 3){
		if(i < 3){
			if(j < 3) return 0;
			if(j < 6) return 1;
			return 2;
		}
		if(i < 6){
			if(j < 3) return 3;
			if(j < 6) return 4;
			return 5;
		}
		if(j < 3) return 6;
		if(j < 6) return 7;
		return 8;
	}
	if(i < 2){
		if(j < 2) return 0;
		return 1;
	}
	if(j < 2) return 2;
	return 3;
}

void Solve(int pos, int val){
	if(flag && pos == V.size()){
		for(int i=0; i<k; i++){
			for(int j=0; j<k; j++){
				printf("%d", M[i][j]);
				if(j != k-1) printf(" ");
			}
			printf("\n");
		}
		flag = false;
	}
	else if(flag){
		int i = V[pos].first, j = V[pos].second;
		if(Vr[i][val] && Vc[j][val] && Va[Area(i, j)][val]){
			M[i][j] = val;
			Vr[i][val] = Vc[j][val] = Va[Area(i, j)][val] = false;
			for(int p=1; p<=k; p++) Solve(pos+1, p);
			Vr[i][val] = Vc[j][val] = Va[Area(i, j)][val] = true;
		}
	}
}

int main() {
	bool g = false;
	while(scanf("%d", &n) == 1){
		if(g) printf("\n");
		g = true;
		k = n*n;
		memset(Vr, true, sizeof Vr);
		memset(Vc, true, sizeof Vc);
		memset(Va, true, sizeof Va);
		int x;
		for(int i=0; i<k; i++)
			for(int j=0; j<k; j++){
				scanf("%d", &x);
				if(!x) V.push_back(make_pair(i, j));
				else Vr[i][x] = Vc[j][x] = Va[Area(i, j)][x] = false;
				M[i][j] = x;
			}
		flag = true;
		for(int i=1; i<=k; i++) Solve(0, i);
		if(flag) printf("NO SOLUTION\n");
		V.clear();
	}
	return 0;
}