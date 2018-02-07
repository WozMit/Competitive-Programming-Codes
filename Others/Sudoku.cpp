#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int M[9][9];
bool Vr[9][10], Vc[9][10], Va[9][10], flag;
vector<pair<int, int> > V;

int Area(int i, int j){
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

void Solve(int pos, int val){
	if(flag && pos == V.size()){
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				printf("%d ", M[i][j]);
				if(j == 2 || j == 5) printf("| ");
			}
			printf("\n");
			if(i == 2 || i == 5){
				for(int k=0; k<11; k++) printf("- ");
				printf("\n");
			}
		}
		flag = false;
	}
	else if(flag){
		int i = V[pos].first, j = V[pos].second;
		if(Vr[i][val] && Vc[j][val] && Va[Area(i, j)][val]){
			M[i][j] = val;
			Vr[i][val] = Vc[j][val] = Va[Area(i, j)][val] = false;
			for(int k=1; k<10; k++) Solve(pos+1, k);
			Vr[i][val] = Vc[j][val] = Va[Area(i, j)][val] = true;
		}
	}
}

int main() {
	printf("\nBienvenido al solver de SuDoKu.\n");
	char option;
	do{
		memset(Vr, true, sizeof Vr);
		memset(Vc, true, sizeof Vc);
		memset(Va, true, sizeof Va);
		int x;
		printf("\nIngrese el SuDoKu en forma de grid, espacios vacios con '0':\n\n");
		for(int i=0; i<9; i++)
			for(int j=0; j<9; j++){
				scanf("%d", &x);
				if(x <= 0) V.push_back(make_pair(i, j));
				else{
					Vr[i][x] = Vc[j][x] = Va[Area(i, j)][x] = false;
					M[i][j] = x;
				}
			}
		printf("\n\n");
		flag = true;
		for(int i=1; i<10; i++) Solve(0, i);
		if(flag) printf("El SuDoKu no tiene solución!\n");
		printf("\nDesea resolver otro SuDoKu? (s/n): ");
		scanf(" %c", &option);
	}while(option == 's');
	return 0;
}

/*INPUT:
0 0 9 0 3 0 0 2 0
0 0 0 1 0 0 0 0 0
1 0 2 0 0 0 3 4 7
0 0 8 0 9 1 0 7 3
2 0 0 0 8 0 0 0 4
9 0 0 2 0 3 0 0 0
0 0 5 7 0 2 0 3 0
0 2 0 8 0 6 0 0 9
4 0 7 0 0 9 0 0 0
*/