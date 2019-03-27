#include <bits/stdc++.h>
using namespace std;

int main() {
	int pages, Lecture[7];
	while(cin >> pages){
		for(int i=0; i<7; i++) cin >> Lecture[i];
		int day = 0;
		while(pages>0){
			pages-=Lecture[day++];
			if(day == 7) day = 0;
		}
		cout << (day == 0 ? 7:day) <<endl;
	}
	return 0;
}