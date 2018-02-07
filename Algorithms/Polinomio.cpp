#include <bits/stdc++.h>
using namespace std;
int A[1000];

int Numb(string s){
	int number = 0;
	for(int i=0; i<s.size(); i++){
		number = number*10 + (s[i]-'0');
	}
	return number;
}

void Read(string s){
	int pos = 0;
	for(int i=0; i<s.size(); i++)
		if(s[i] == '+' || s[i] == '-' || i == s.size()-1){
			int sgn = 1;
			if(i == s.size()-1 && pos == 0 && s[pos] == '-'){
				sgn = -1;
				pos++;
			}
			else if(s[pos-1] == '-') sgn = -1;
		    string term = s.substr(pos, i-(i == s.size()-1 ? pos-1:pos));
			int ex = 0, coef;
			bool flag = true;
			for(int j=term.size()-1; j>-1 && flag; j--){
				if(term[j] == '^')
					ex = Numb(term.substr(j+1, term.size()-(j+1)));
				else if(term[j] == 'x'){
						coef = j==0 ? 1:Numb(term.substr(0, j));
						if(j == term.size()-1) ex = 1;
						flag = false;
				}
			}
			if(flag) coef = Numb(term);
			A[ex]+= sgn*coef;
			pos = i+1;
		}
}

int main() {
	Read("x");
	for(int i=0; i<4; i++)
		cout << i << " = " << A[i] << endl;
	return 0;
}