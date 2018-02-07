#include <bits/stdc++.h>
using namespace std;

int main() {
	int rows, columns, pos;
	while(cin >> rows >> columns){
		char M[rows][columns];
		for(int i=0; i<rows; i++){
			if(i%2 == 0) memset(M[i], '#', sizeof(M[i]));
			else{
				memset(M[i], '.', sizeof(M[i]));
				pos = 0;
				if((i-1)%4 == 0) pos = columns-1;
				M[i][pos] = '#';
			}
		}
		//Mostrar
		for(int i=0; i<rows; i++){
			for(int j=0; j<columns; j++) cout << M[i][j];
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}