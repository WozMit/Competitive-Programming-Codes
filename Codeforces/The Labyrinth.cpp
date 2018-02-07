#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
const int MAX1 = 1003, MAX2 = 1000003;
int n, m, C[MAX2], N[MAX1][MAX1], k, mx[] = {-1, 0, 1, 0}, my[] = {0, 1, 0, -1};
bool M[MAX1][MAX1];

bool Safe(int i, int j){ return i>=0 && i<n && j>=0 && j<m; }

void DFS(int i, int j, int c){
	if(N[i][j] == -1){
		k++;
		N[i][j] = c;
		for(int move=0; move<4; move++){
			int i1 = i+mx[move], j1 = j+my[move];
			if(Safe(i1, j1) && M[i1][j1]) DFS(i1, j1, c);
		}
	}
}

int main(){
	while(scanf("%d %d", &n, &m) == 2){
		char ch;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){
				scanf(" %c", &ch);
				M[i][j] = ch == '.' ? true:false;
				N[i][j] = -1;
			}
		int c = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(M[i][j] && N[i][j] == -1){
					k = 0;
					DFS(i, j, c);
					C[c++] = k;
				}
		char s[MAX1] = "";
		for(int i=0; i<n; i++){
			int len = 0;
			for(int j=0; j<m; j++)
				if(M[i][j]) s[len++] = '.';
				else{
					int gg = 0;
					set<int> S;
					for(int move=0; move<4; move++){
						int i1 = i+mx[move], j1 = j+my[move];
						if(Safe(i1, j1) && M[i1][j1]) S.insert(N[i1][j1]);
					}
					vector<int> T(S.begin(), S.end());
					for(int k=0; k<T.size(); k++) gg += C[T[k]];
					s[len++] = ((gg+1)%10)+'0';
				}
			s[len] = '\0';
			puts(s);
		}

	}
	return 0;
}