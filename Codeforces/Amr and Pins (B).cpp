#include <bits/stdc++.h>
using namespace std;

int main() {
	double r, x, y, xp, yp, d;
	while(cin >> r >> x >> y >> xp >> yp){
		d = sqrt((xp-x)*(xp-x)+(yp-y)*(yp-y));
		cout << ceil(d/(2*r)) <<endl;
	}
	return 0;
}