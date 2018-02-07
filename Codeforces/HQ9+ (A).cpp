#include <bits/stdc++.h>
using namespace std;

bool Contains(string cad){
	for(int i=0; i<cad.size(); i++)
		if(cad[i] == 'H' || cad[i] == 'Q' || cad[i] == '9') return true;
	return false;
}

int main() {
	string cad;
	while(cin >> cad)
		cout << (Contains(cad) ? "YES":"NO") <<endl;
	return 0;
}