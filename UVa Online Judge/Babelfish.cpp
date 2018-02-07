#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string, string> M;
	string cad;
	while(getline(cin, cad) && cad!=""){
		for(int i=0; i<cad.size(); i++){
			if(cad[i] == ' '){
				M[cad.substr(i+1, cad.size()-i-1)] = cad.substr(0, i);
				break;
			}
		}
	}
	while(getline(cin, cad) && cad!=""){
		cout << (M.count(cad) ? M[cad]:"eh") <<endl;
	}
	return 0;
}