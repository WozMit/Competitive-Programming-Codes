#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s1, s2;
	while(cin >> n){
		cin >> s1 >> s2;
		int gg = 0, aux;
		for(int i=0; i<n; i++){
			aux = abs((s1[i]-'0')-(s2[i]-'0'));
			gg+=min(aux, 10-aux);
		}
		cout << gg <<endl;
	}
	return 0;
}