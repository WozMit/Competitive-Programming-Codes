//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
char str[30*10+50], line[30+50];

int main() {
	strcpy(str, "");
	while(gets(line) && strncmp(line, ".......", 7) != 0){
		strcat(str, line);
		strcat(str, " ");
	}
	printf("%s\n", str);
	return 0;
}

/*INPUT:
I love CS3233 Competitive
Programming. i also love
AlGoRiThM
.......you must stop after reading this line as it starts with 7 dots
after the first input block, there will be one loooooooooooong line...
*/