#include <bits/stdc++.h>
using namespace std;

int main() {
	double n;
	while(1){
		cout << "Ingrese n: ";
		cin >> n;
		double x, y, sxy = 0, sx = 0, sy = 0, sxx = 0;
		for(int i=0; i<n; i++){
			cout << "x" << i+1 << ", y" << i+1 << ": ";
			cin >> x >> y;
			sxy += x*y;
			sx += x;
			sy += y;
			sxx += x*x;
		} 
		double a = (n*sxy-sx*sy)/(n*sxx-sx*sx), da;
		double b = (sy-a*sx)/n, db, e = -1;
		string op;
		cout << "Variaciones y errores?(si/no) ";
		cin >> op;
		if(op == "si" || op == "SI" || op == "Si"){
			cout << "Error: ";
			cin >> e;
			da = (sqrt(n)*e)/sqrt(n*sxx-sx*sx);
			db = e/sqrt(n);
		}
		cout << "a = " << a;
		if(e != -1) cout << " +- " << da;
		cout << endl;
		cout << "b = " << b;
		if(e != -1) cout << " +- " << db;
		cout << endl;
		cout << "y = " << a << "x" << (b < 0 ? "":"+") << b << endl;
		break;
	}
	return 0;
}