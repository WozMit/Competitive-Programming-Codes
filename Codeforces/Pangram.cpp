#include <bits/stdc++.h>
using namespace std;
bool Carac[26];

int main() {
	int n, car;
	string s;
	while(cin >> n >> s){
		memset(Carac, false, sizeof Carac);
		for(int i=0; i<n; i++){
			int car = int(s[i]), pos;
			if(car < 91) pos = 65;
			else if(car < 123) pos = 97;
			Carac[car-pos] = true;
		}
		for(int i=0; i<26; i++){
			if(!Carac[i]){
				cout << "NO" << endl;
				break;
			}
			if(i == 25) cout << "YES" << endl;
		}
	}
	return 0;
}