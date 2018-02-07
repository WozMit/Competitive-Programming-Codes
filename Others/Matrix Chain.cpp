#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int> > V;
int DP[100][100], S[100][100];

int MatrixChain(int i, int j){
	if(DP[i][j] != -1) return DP[i][j];
	if(i == j) return 0;
	int gg = 1<<30;
	for(int k=i; k<j; k++){
		int temp = MatrixChain(i, k) + MatrixChain(k+1, j) + V[i].first*V[k].second*V[j].second;
		if(temp < gg){
			gg = temp;
			S[i][j] = k;
		}
	}
	return DP[i][j] = gg;
}

void Print(int i, int j){
	if(i == j) printf("A%d", i+1);
	else{
		printf("(");
		Print(i, S[i][j]);
		Print(S[i][j]+1, j);
		printf(")");
	}
}

int main() {
	V.push_back(make_pair(10,100));
	V.push_back(make_pair(100,5));
	V.push_back(make_pair(5,50));
	memset(DP, -1, sizeof DP);
	int price = MatrixChain(0, V.size()-1);
	Print(0, V.size()-1);
	printf("\n");
	printf("price: %d\n", price);
	return 0;
}