#include <bits/stdc++.h>
using namespace std;

int main() {
	string w = "CODEFORCES", s;
	while(cin >> s){
		int pos = 0;
		for(int i=0; i<s.size() && pos<10; i++){
			if(w[pos] != s[i]) break;
			pos++;
		}
		if(pos == 10) cout << "YES" << endl;
		else{
			if(s.size()<10) cout << "NO" << endl;
			else{
				if(w.substr(pos, 10-pos) == s.substr(s.size()-10+pos, 10-pos)) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
	}
	return 0;
}