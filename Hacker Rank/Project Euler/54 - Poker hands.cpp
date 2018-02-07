//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
#define mp make_pair
using namespace std;

struct card{
	int value;
	char suit;
	card(){}
	card(string s){
		if(isdigit(s[0])) value = s[0] - '0';
		else if(s[0] == 'T') value = 10;
		else if(s[0] == 'J') value = 11;
		else if(s[0] == 'Q') value = 12;
		else if(s[0] == 'K') value = 13;
		else value = 14;
		suit = s[1];
	}
	bool operator <(card b)const{ return value < b.value; }
};

struct hand{
	card h[5];
	bool sorted;
	hand(){ sorted = false; }
	void print(){
		for(int i=0; i<5; i++) printf("(%d, %c) ", h[i].value, h[i].suit);
		printf("\n");
	}
	
	bool isRoyalFlush(){
		if(!sorted) sort(h, h+5), sorted = true;
		for(int i=0; i<5; i++)
			if(h[i].value != i + 10 || (i && h[i].suit != h[i-1].suit))
				return false;
		return true;
	}
	
	int isStraightFlush(){
		if(!sorted) sort(h, h+5), sorted = true;
		for(int i=1; i<5; i++)
			if(h[i].suit != h[i-1].suit) return -1;
			else if(i == 4 && h[4].value == 14 && h[0].value == 2) return 5;
			else if(h[i].value != h[i-1].value + 1) return -1;
		return h[4].value;
	}
	
	int isPoker(){
		if(!sorted) sort(h, h+5), sorted = true;
		bool flag = true;
		for(int i=1; i<4 && flag; i++)
			if(h[i].value != h[i-1].value) flag = false;
		for(int i=2; i<5 && !flag; i++)
			if(h[i].value != h[i-1].value) return -1;
		return (h[0].value == h[1].value ? h[0].value:h[4].value);
	}
	
	int isFullHouse(){
		if(!sorted) sort(h, h+5), sorted = true;
		if(h[0].value == h[1].value && h[1].value == h[2].value && h[3].value == h[4].value)
			return h[0].value;
		if(h[0].value == h[1].value && h[2].value == h[3].value && h[3].value == h[4].value)
			return h[2].value;
		return -1;
	}
	
	bool isFlush(){
		if(!sorted) sort(h, h+5), sorted = true;
		for(int i=1; i<5; i++)
			if(h[i].suit != h[i-1].suit) return false;
		return true;
	}
	
	int isStraight(){
		if(!sorted) sort(h, h+5), sorted = true;
		for(int i=1; i<5; i++)
			if(i == 4 && h[4].value == 14 && h[0].value == 2) return 5;
			else if(h[i].value != h[i-1].value + 1) return -1;
		return h[4].value;
	}
	
	int isThreeOfaKind(){
		if(!sorted) sort(h, h+5), sorted = true;
		if(h[0].value == h[1].value && h[1].value == h[2].value) return h[0].value;
		if(h[1].value == h[2].value && h[2].value == h[3].value) return h[1].value;
		if(h[2].value == h[3].value && h[3].value == h[4].value) return h[2].value;
		return -1;
	}
	
	pair<int, pair<int, int> > isTwoPairs(){
		if(!sorted) sort(h, h+5), sorted = true;
		if(h[0].value == h[1].value && h[2].value == h[3].value)
			return mp(h[2].value, mp(h[0].value, h[4].value));
		if(h[0].value == h[1].value && h[3].value == h[4].value)
			return mp(h[4].value, mp(h[1].value, h[2].value));
		if(h[1].value == h[2].value && h[3].value == h[4].value)
			return mp(h[4].value, mp(h[2].value, h[0].value));
		return mp(-1, mp(-1, -1));
	}
	
	pair<int, pair<int, pair<int, int> > > isPair(){
		if(!sorted) sort(h, h+5), sorted = true;
		if(h[0].value == h[1].value)
			return mp(h[0].value, mp(h[0].value, mp(h[3].value, h[2].value)));
		if(h[1].value == h[2].value)
			return mp(h[1].value, mp(h[4].value, mp(h[3].value, h[0].value)));
		if(h[2].value == h[3].value)
			return mp(h[2].value, mp(h[4].value, mp(h[1].value, h[0].value)));
		if(h[3].value == h[4].value)
			return mp(h[3].value, mp(h[2].value, mp(h[1].value, h[0].value)));
		return mp(-1, mp(-1, mp(-1, -1)));
	}
	
	bool operator >(hand h2){
		if(isRoyalFlush() != h2.isRoyalFlush()) return isRoyalFlush() > !h2.isRoyalFlush();
		if(isStraightFlush() != h2.isStraightFlush()) return isStraightFlush() > h2.isStraightFlush();
		if(isPoker() != h2.isPoker()) return isPoker() > h2.isPoker();
		if(isFullHouse() != h2.isFullHouse()) return isFullHouse() > h2.isFullHouse();
		if(isFlush() != h2.isFlush()) return isFlush() > h2.isFlush();
		if(isStraight() != h2.isStraight()) return isStraight() > h2.isStraight();
		if(isThreeOfaKind() != h2.isThreeOfaKind()) return isThreeOfaKind() > h2.isThreeOfaKind();
		if(isTwoPairs() != h2.isTwoPairs()) return isTwoPairs() > h2.isTwoPairs();
		if(isPair() != h2.isPair()) return isPair() > h2.isPair();
		return mp(h[4].value, mp(h[3].value, mp(h[2].value, mp(h[1].value, h[0].value))))
		> mp(h2.h[4].value, mp(h2.h[3].value, mp(h2.h[2].value, mp(h2.h[1].value, h2.h[0].value))));
	}
};

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int n; scanf("%d", &n);
	while(n--){
		hand hand1, hand2;
		string s;
		for(int i=0; i<10; i++){
			cin >> s;
			if(i < 5) hand1.h[i] = card(s);
			else hand2.h[i-5] = card(s);
		}
		if(hand1 > hand2) puts("Player 1");
		else puts("Player 2");
	}
	#ifdef WozMit
		printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		//cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s\n";
	#endif
	return 0;
}
