#include <bits/stdc++.h>
using namespace std;

bool Lucky(long long int number){
	number = abs(number);
	while(number>0){
		if(number%10 == 8) return true;
		number/=10;
	}
	return false;
}

int main() {
	long long int floOr;
	while(cin >> floOr){
		int count = 1;
		while(!Lucky(floOr+1)){
			floOr++;
			count++;
		}
		cout << count <<endl;
	}
	return 0;
}