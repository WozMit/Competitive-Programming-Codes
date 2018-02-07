#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char s[105];

bool vowel(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'y' || c == 'Y';
}

int main() {
	while(scanf("%s", s) != EOF){
		int n = (int)strlen(s);
		for(int i=0; i<n; i++)
			if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
		for(int i=0; i<n; i++)
			if(!vowel(s[i])) printf(".%c", s[i]);
		printf("\n");
	}
	return 0;
}