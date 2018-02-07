#include <bits/stdc++.h>
using namespace std;

bool Leap(int n){ return (n%4 == 0 && (n%100 != 0 || n%400 == 0)); }

int main() {
	int gg = 0, day = 1, D[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for(int n=1901; n<2001; n++){
		for(int i=0; i<12; i++){
			if(day == 6) gg++;
			day += (i == 1 && Leap(n)) ? 29:D[i];
			day %= 7;
		}
	}
	cout << gg << endl;
	return 0;
}