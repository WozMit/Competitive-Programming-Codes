//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
const int MAX_VAL = 1000;
int S[MAX_VAL];
char T[MAX_VAL], p[MAX_VAL];

void KMP(){
	int j = 0;
	S[0] = 0;
	for(int i=1; i<strlen(p); i++){
		while(j && p[i] != p[j]) j = S[j-1];
		S[i] = (p[i] == p[j]) ? (j++)+1:0;
	}
	j = 0;
	bool found = false;
	for(int i=0; !found && i<strlen(T); i++){
		while(j && T[i] != p[j]) j = S[j-1];
		if(T[i] == p[j]) j++;
		if(j == strlen(p)){
			printf("\"%s\" found in (%d, %d).\n",p, i-j+1, i);
			found = true;
		}
	}
	if(!found) printf("\"%s\" not found!\n", p);
}

int main() {
	string T1;
	while(cin >> T1){
		strcpy(T, T1.c_str());
		printf("T: \"%s\"\n");
		int q;
		scanf("%d", &q);
		while(q--){
			scanf("%s", p);
			KMP();
		}
		printf("\n");
	}
	return 0;
}

/*INPUT:
holamama
3
mama
lamo
amama

abcxabcdabxabcdabcdabcy
1
abcdabcy
*/