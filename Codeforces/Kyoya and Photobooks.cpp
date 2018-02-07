#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	string s, act;
	while(cin >> s){
		cout << 26+s.size()*25 << endl;
	}
	return 0;
}