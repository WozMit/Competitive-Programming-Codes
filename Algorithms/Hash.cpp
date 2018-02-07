#include <bits/stdc++.h>
using namespace std;

unsigned long long int Hash(string txt){			//Bad done
	unsigned long long int h = 0;
	unsigned long long int prod = 1;
	for(int i=0; i<txt.size(); i++){
		prod*= i == 0 ? 1:29;
		h+=pow(txt[i], i)*prod;
	}
	return h;
}

int main() {
	return 0;
}