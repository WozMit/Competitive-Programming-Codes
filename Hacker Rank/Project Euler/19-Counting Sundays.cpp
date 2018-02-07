//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
const int s = 688; //Number of sundays on the frist of the month in 400 years
int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int w(int d, int m, ll py){
	int y = m < 3 ? py-1:py;
	return (y+y/4-y/100+y/400+t[m-1]+d)%7;
}

bool leap(ll y){ return (y%4 == 0 && (y%100 != 0 || y%400 == 0)); }

int Sol(int to_month, ll to_year){
	if(to_year < 1900) return 0;
	to_month --;
	int gg = 0, d = 1;
	ll year = 1900;
	if(to_year > 2000){
		while(year < 2000){
			for(int month=0; month<12; month++){
				if(!d) gg++;
				d = (d + (month == 1 && leap(year) ? 29:m[month]))%7;
			}
			year ++;
		}
		ll n400y = (to_year-2000)/400;
		gg += n400y*s;
		year += n400y*400;
	}
	while(year < to_year){
		for(int month=0; month<12; month++){
			if(!d) gg++;
			d = (d + (month == 1 && leap(year) ? 29:m[month]))%7;
		}
		year ++;
	}
	int month = 0;
	while(month <= to_month){
		if(!d) gg++;
		d = (d + (month == 1 && leap(year) ? 29:m[month]))%7;
		month++;
	}
	return gg;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	#ifdef WozMit
		clock_t _start = clock();
	#endif
	int t;
	cin >> t;
	while(t--){
		ll y1, y2;
		int m1, d1, m2, d2;
		cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
		d1 --;
		if(!d1){
			m1--;
			if(!m1) y1--, m1 = 12;
		}
		cout << Sol(m2, y2)-Sol(m1, y1) << "\n";
	}
	#ifdef WozMit
		//printf("%30c Executed in %.3f s.", 32, (double)(clock() - _start)/CLOCKS_PER_SEC);
		cout<<string(30,' ')<<"Executed in "<<(double)(clock()-_start)/CLOCKS_PER_SEC<<"s";
	#endif
	return 0;
}
