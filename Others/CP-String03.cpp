//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main() {
	char T[] = "Hola2MundO124", vowel[] = "aeiou";
	int con = 0, vow = 0, dig = 0;
	for(int i=0; i<strlen(T); i++){
		T[i] = tolower(T[i]);
		if(isalpha(T[i])){
			if(strchr(vowel, T[i]) != NULL) vow++;
			else con++;
		}
		else dig++;
	}
	puts(T);
	printf("Consonants: %d\nVowels: %d\nDigits: %d\n", con, vow, dig);
	return 0;
}