#include <bits/stdc++.h>
using namespace std;

int main() {
	int queries;
	string operation;
	while(cin >> queries){
		int total = 0, donation;
		while(queries--){
			cin >> operation;
			if(operation == "donate"){
				cin >> donation;
				total+=donation;
			}
			else cout << total <<endl;
		}
	}
	return 0;
}