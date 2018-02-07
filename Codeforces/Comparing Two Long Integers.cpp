//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
const int MAX = 1000005;

int main() {
	char a[MAX], b[MAX];
	scanf("%s", a);
	scanf("%s", b);
	int n = (int) strlen(a), m = (int) strlen(b);
	reverse(a, a+n);
	reverse(b, b+m);
	while(n < m) a[n++] = '0';
	while(m < n) b[m++] = '0';
	reverse(a, a+n);
	reverse(b, b+m);
	int x = strcmp(a, b);
	if(x < 0) printf("<\n");
	else if(x > 0) printf(">\n");
	else printf("=\n");
	return 0;
}