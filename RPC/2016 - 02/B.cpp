#include <bits/stdc++.h>
using namespace std;
char M[105][105];
int main(){
	int n;
	while(scanf("%d", &n) == 1){
		for(int i = 0 ; i <4*n+1 ; i++)
			for(int j = 0 ; j <4*n+1 ; j++)
				M[i][j] = ' ';
		for(int i = 0 ; i <4*n+1 ; i++)
			M[n][i] = '*';
		for(int i = 0 ; i <4*n+1 ; i++)
			M[4*n-n][i] = '*';
			
		for(int i = 0 ; i <4*n+1 ; i++)
			M[i][n] = '*';
		for(int i = 0 ; i <4*n+1 ; i++)
			M[i][4*n-n] = '*';

		for(int i = 0 ; i <4*n+1-n ; i++)
			M[0+i][n+i] = '*';
		for(int i = 0 ; i <4*n+1-n ; i++)
			M[n+i][0+i] = '*';

		for(int i = 0 ; i <4*n+1-n ; i++)
			M[0+i][4*n-n-i] = '*';
		for(int i = 0 ; i <4*n+1-n ; i++)
			M[4*n-i][n+i] = '*';
		
		for(int i = 0 ; i <n ; i++){
			for(int j = 0 ; j <4*n-n+1 ; j++){
				cout << M[i][j];
			}
			cout << endl;
		}
		for(int j = 0 ; j <4*n+1 ; j++)
			cout << M[n][j];
		cout << endl;
		
		for(int i = n+1; i <2*n+1 ; i++){
			for(int j = 0 ; j <5*n+1-i ; j++){
				cout << M[i][j];
			}
			cout << endl;
		}
		
		for(int i = 2*n+1; i <3*n ; i++){
			for(int j = 0 ; j <4*n-n+i-2*n+1 ; j++){
				cout << M[i][j];
			}
			cout << endl;
		}
		for(int j = 0 ; j <4*n+1 ; j++)
			cout << M[n][j];
		cout << endl;
		for(int i = 4*n-n+1 ; i <4*n+1 ; i++){
			for(int j = 0 ; j <4*n-n+1 ; j++){
				cout << M[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}

