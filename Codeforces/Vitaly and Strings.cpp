#include <bits/stdc++.h>
using namespace std;

string Next(string s){
	char car = s[s.size()-1];
	car = (car == 'z' ? 'a':char(int(car)+1));
	return s.substr(0, s.size()-1)+car;
}

int main() {
	string s, t, gg;
	while(cin >> s >> t){
		gg = Next(s);
		if(gg == t) cout << "No such string" << endl;
		else cout << gg << endl;
	}
	return 0;
}