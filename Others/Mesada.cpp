//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <time.h>
#define db(x) cout << #x << " = " << x << "\n";
using namespace std;
int Dmonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string Nmonth[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
string Nday[] = {"lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo"};
int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

int z(int d, int m, int y){
	if(m < 3) y --;
	int gg = (y + y/4 - y/100 + y/400 + t[m-1] + d)%7;
	return (gg + 6)%7;
}

bool bis(int y){ return (y%4 == 0 && (y%100 != 0 || y%400 == 0)); }

int main(){
	while(1){
		int d, m, y;
		printf("\n-----------------------------------------------------------------------------\n");
		printf("Fecha actual (dd/mm/aaaa): ");
		scanf("%d/%d/%d", &d, &m, &y);
		int day = z(d, m, y);
		printf("\n\nFecha inicial: %s %d de %s de %d\n", Nday[day].c_str(), d, Nmonth[m-1].c_str(), y);
		int nday = m == 2 && bis(y) ? 29:Dmonth[m-1], nweek = z(nday, m, y);
		printf("\n\nFecha final: %s %d de %s de %d\n", Nday[nweek].c_str(), nday, Nmonth[m-1].c_str(), y);
		printf("\n/////////////// PRESUPUESTO ///////////////\n");
		double gg = 0.0;
		int commondays = 0, pooldays = 1;
		for(int i=d; i<=nday; i++){
			if(day < 5) commondays++;
			if(day == 6 && i < nday) pooldays++;
			day = (day+1)%7;
		}
		printf("\n-Propina diaria (S/.%.1f) x2 x%d dias habiles (lunes - viernes): S/.%.1f\n", 2.5, commondays, 5.0*commondays);
		gg += 5.0*commondays;
		printf("\n-Piscina (S/.%.1f) x%d dias (una vez por semana): S/.%.1f\n", 4.0, pooldays, 4.0*pooldays);
		gg += 4.0*pooldays;
		printf("\n-Pago de celular: S/.%.1f\n", 22.0);
		gg += 22.0;
		printf("\n %30c TOTAL: S/.%.1f\n", 32, gg);
	}
	return 0;
}
