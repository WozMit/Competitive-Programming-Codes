#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int n;
	string s;
	while(scanf("%d", &n) == 1){
		int gg = 0;
		while(n--){
			cin >> s;
			if(s[0] == '+' || s[1] == '+') gg++;
			else gg--;
		}
		printf("%d\n", gg);
	}
	return 0;
}