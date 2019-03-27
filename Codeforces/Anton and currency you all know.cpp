#include <bits/stdc++.h>
using namespace std;

int main() {
	string numb;
	while(cin >> numb){
		int pos = -1, dig;
		for(int i=0; i<numb.size()-1; i++){
			dig = numb[i]-'0';
			if(dig%2 == 0){
				pos = i;
				if(dig<numb[numb.size()-1]-'0') break;
			}
		}
		if(pos == -1) numb = "-1";
		else numb = numb.substr(0, pos)+numb[numb.size()-1]+numb.substr(pos+1, numb.size()-(pos+2))+numb[pos];
		cout << numb <<endl;
	}
	return 0;
}